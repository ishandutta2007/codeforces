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
    static const int sigma = 14;
 
    AhoCorasick(const vector<string>& v, const vector<int>& c) {
        t.pb(node());
        for (int i = 0; i < sz(v); ++i) {
            add(v[i], c[i]);
        }
        build();
    }
 
    int getNumber(char c) {
        return c - 'a';
    }
 
    struct node {
        int link;
        int to[sigma];
        bool term;
        int compressed;
        int depth;
        ll price;
        node() {
            link = -1;
            term = false;
            memset(to, -1, sizeof(to));
            compressed = -1;
            depth = 0;
            price = 0;
        }
    };
 
    vector<node> t;
 
    void add(const string& s, ll cost) {
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
        t[v].price += cost;
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
                if (t[u].compressed != -1) {
                    t[u].price += t[t[u].compressed].price;
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

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<string> t(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> c[i];
    }

    AhoCorasick AC(t, c);

    string s;
    cin >> s;

    vector<string> blocks;
    string curr = "";
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '?') {
            blocks.pb(curr);
            curr = "";
        } else {
            curr += s[i];
        }
    }
    blocks.pb(curr);

    const int k = 14;
    int N = sz(AC.t);
    const ll infty = 1e18;

    vector<vector<vector<ll> > > dp(2, vector<vector<ll> >(1 << k, vector<ll>(N, -infty)));
    dp[0][0][0] = 0;
    int ptr = 0;

    ll ans = -infty;

    for (int i = 0; i < sz(blocks); ++i) {
        vector<int> change(N);
        vector<ll> add(N);
        for (int init = 0; init < N; ++init) {
            int v = init;
            for (int j = 0; j < sz(blocks[i]); ++j) {
                int c = AC.getNumber(blocks[i][j]);
                v = AC.t[v].to[c];
                add[init] += AC.t[v].price;
            }
            change[init] = v;
        }
        dp[ptr ^ 1] = vector<vector<ll> >(1 << k, vector<ll>(N, -infty));
        for (int mask = 0; mask < (1 << k); ++mask) {
            if (__builtin_popcount(mask) != i) {
                continue;
            }
            if (i != sz(blocks) - 1) {
                for (int b = 0; b < k; ++b) {
                    if (bit(mask, b)) {
                        continue;
                    }
                    for (int v = 0; v < N; ++v) {
                        int to = change[v];
                        to = AC.t[to].to[b];
                        dp[ptr ^ 1][mask | (1 << b)][to] = max(dp[ptr ^ 1][mask | (1 << b)][to], dp[ptr][mask][v] + add[v] + AC.t[to].price);
                    }
                }
            } else {
                for (int v = 0; v < N; ++v) {
                    ans = max(ans, dp[ptr][mask][v] + add[v]);
                }
            }
        }
        ptr ^= 1;
    }

    cout << ans << "\n";

}