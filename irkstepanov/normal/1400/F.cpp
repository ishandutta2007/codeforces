#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct AhoCorasick {
    static const int sigma = 9;
 
    AhoCorasick(const vector<string>& v) {
        t.pb(node());
        for (int i = 0; i < sz(v); ++i) {
            add(v[i]);
        }
        build();
    }
 
    int getNumber(char c) {
        return c - '1';
    }
 
    struct node {
        int link;
        int to[sigma];
        bool term;
        int compressed;
        int depth;
        node() {
            link = -1;
            term = false;
            memset(to, -1, sizeof(to));
            compressed = -1;
            depth = 0;
        }
    };
 
    vector<node> t;
 
    void add(const string& s) {
        int v = 0;
        for (int i = 0; i < sz(s); ++i) {
            int c = getNumber(s[i]);
            if (t[v].to[c] == -1) {
                t[v].to[c] = sz(t);
                t.pb(node());
            }
            v = t[v].to[c];
        }
        t[v].term = true;
    }
 
    void build() {
        t[0].link = 0;
        for (int i = 0; i < sigma; ++i) {
            if (t[0].to[i] == -1) {
                t[0].to[i] = 0;
            }
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            //cout << "!" << v << endl;
            q.pop();
            for (int c = 0; c < sigma; ++c) {
                int u = t[v].to[c];
                if (t[u].link != -1) {
                    continue;
                }
                t[u].link = (v == 0 ? 0 : t[t[v].link].to[c]);
                t[u].depth = t[v].depth + 1;
                if (t[t[u].link].term) {
                    t[u].compressed = t[u].link;
                } else {
                    t[u].compressed = t[t[u].link].compressed;
                }
                for (int d = 0; d < sigma; ++d) {
                    if (t[u].to[d] != -1) {
                        continue;
                    }
                    t[u].to[d] = t[t[u].link].to[d];
                }
                q.push(u);
            }
        }
    }
};

vector<string> bad;

void rec(int sum, string t, int x) {
    if (sum == x) {
        for (int i = 0; i < sz(t); ++i) {
            int z = 0;
            for (int j = i; j < sz(t); ++j) {
                z += t[j] - '0';
                if (x % z == 0 && x != z) {
                    return;
                }
            }
        }
        bad.pb(t);
    }
    for (int d = 2; d <= 9 && sum + d <= x; ++d) {
        rec(sum + d, t + char(d + '0'), x);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int x;
    cin >> x;
    if (x == 1) {
        bad.pb("1");
    } else {
        string t = "";
        rec(0, t, x);
    }

    AhoCorasick AC(bad);
    int N = sz(AC.t);
    const int infty = 1e9;

    vector<vector<int> > dp(2, vector<int>(N, infty));
    dp[0][0] = 0;
    int ptr = 0;

    for (int i = 0; i < sz(s); ++i) {
        int c = AC.getNumber(s[i]);
        dp[ptr ^ 1].assign(N, infty);
        for (int v = 0; v < N; ++v) {
            if (dp[ptr][v] == infty) {
                continue;
            }
            dp[ptr ^ 1][v] = min(dp[ptr ^ 1][v], dp[ptr][v] + 1);
            int nx = AC.t[v].to[c];
            if (AC.t[nx].term || AC.t[nx].compressed != -1) {
                continue;
            }
            dp[ptr ^ 1][nx] = min(dp[ptr ^ 1][nx], dp[ptr][v]);
        }
        ptr ^= 1;
    }

    int ans = infty;
    for (int v = 0; v < N; ++v) {
        ans = min(ans, dp[ptr][v]);
    }
    cout << ans << "\n";

}