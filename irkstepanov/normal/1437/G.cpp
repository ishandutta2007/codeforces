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

struct SegmentTree {
    int n;
    vector<multiset<int> > t;

    SegmentTree(int n) : n(n) {
        t.resize(2 * n);
    }

    void insert(int l, int r, int val) {
        for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) {
                t[l].insert(val);
            }
            if (!(r & 1)) {
                t[r].insert(val);
            }
        }
    }

    void erase(int l, int r, int val) {
        for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) {
                multiset<int>::iterator it = t[l].lower_bound(val);
                assert(*it == val);
                t[l].erase(it);
            }
            if (!(r & 1)) {
                multiset<int>::iterator it = t[r].lower_bound(val);
                assert(*it == val);
                t[r].erase(it);
            }
        }
    }

    int get(int pos) {
        int ans = -1;
        for (pos += n; pos; pos >>= 1) {
            if (!t[pos].empty()) {
                ans = max(ans, *(--t[pos].end()));
            }
        }
        return ans;
    }

};

struct AhoCorasick {
    static const int sigma = 26;

    vector<int> positions;

    AhoCorasick(const vector<string>& v) {
        t.pb(node());
        for (int i = 0; i < sz(v); ++i) {
            add(v[i]);
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
        positions.pb(v);
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

vector<int> tin, tout;
vector<vector<int> > g;
int timer = 0;

void dfs(int v) {
    tin[v] = timer++;
    tout[v] = tin[v];
    for (int to : g[v]) {
        dfs(to);
        tout[v] = timer++;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    AhoCorasick AC(s);
    int N = sz(AC.t);
    g.resize(N);
    tin.resize(N);
    tout.resize(N);
    for (int v = 1; v < N; ++v) {
        int p = AC.t[v].link;
        g[p].pb(v);
        //cout << p << " " << v << endl;
    }

    vector<int> a(n, 0);
    dfs(0);

    SegmentTree ST(timer);
    for (int i = 0; i < n; ++i) {
        int v = AC.positions[i];
        ST.insert(tin[v], tout[v], 0);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            cin >> i;
            --i;
            int v = AC.positions[i];
            int val;
            cin >> val;
            ST.erase(tin[v], tout[v], a[i]);
            a[i] = val;
            ST.insert(tin[v], tout[v], a[i]);

        } else {
            int ans = -1;
            int v = 0;
            string t;
            cin >> t;
            for (int i = 0; i < sz(t); ++i) {
                int c = AC.getNumber(t[i]);
                v = AC.t[v].to[c];
                //cout << v << endl;
                ans = max(ans, ST.get(tin[v]));
            }
            //cout << "!" << ST.get(1) << endl;
            cout << ans << "\n";
        }
    }

}