// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 


#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mt make_tuple
#define f first
#define s second

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { if (b < a) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = (int)2e9;
const int maxn = 2e6 + 5, inf = 2e9;

const int mod = 1e9 + 7;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % mod;
    } else {
        return (1LL* binpow(n, s - 1) * n) % mod;
    }
}

vector<int> g[maxn];
map<int, int> sot;
vector<int> a;
bool used[maxn];
int mda[maxn];

int mx, mx2;

int sz, sz2;

void go(int v) {
    used[v] = 1;
    sz += g[v].size(), sz2 += 1;
    
    int val = mda[v];
    if (val >= mx) {
        mx2 = mx;
        mx = val;
    } else if (val >= mx2) {
        mx2 = val;
    }


    for (int i : g[v]) {
        if (!used[i]) {
            go(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (!sot.count(x)) {
            sot[x] = sot.size();
            mda[sot[x]] = x;
        }
        if (!sot.count(y)) {
            sot[y] = sot.size();
            mda[sot[y]] = y;
        }
        int sx = sot[x], sy = sot[y];
        g[sx].pb(sy);
        g[sy].pb(sx);
        a.pb(sx);
        a.pb(sy);
    }

    int res = 0;
    for (int i : a) {
        if (!used[i]) {
            sz = 0;
            mx = 0, mx2 = 0;
            sz2 = 0;
            go(i);
            sz /= 2;
            if (sz == sz2 - 1) {
                res = max(res, mx2);
            } else if (sz == sz2) {
                res = max(res, mx);
            } else {
                cout << -1;
                exit(0);
            }
        }
    }
    cout << res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}