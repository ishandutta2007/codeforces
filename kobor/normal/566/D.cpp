#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

constexpr int N = 2e5 + 5;

int par[N];

int Find(int x) {
    return x == par[x] ? x : par[x] = Find(par[x]);
}

void Union(int x, int y) {
    x = Find(x), y = Find(y);
    par[x] = y;
}

void solve() {
    int n, q;
    cin >> n >> q;
    FOR(i, 0, n) par[i] = i;
    set<int> s;
    FOR(i, 0, n) s.insert(i);
    FOR(i, 0, q) {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        if(t == 1) Union(a, b);
        if(t == 2) {
            auto it = s.upper_bound(a);
            int pier = *prev(it);
            while(it != s.end() && (*it) <= b) {
                Union(pier, *it);
                s.erase(it++);
            }
        }
        if(t == 3) cout << (Find(a) == Find(b) ? "YES\n" : "NO\n");
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin >> tt;
	// FOR(te, 0, tt) {
	// 	// cout << "Case #" << te + 1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}