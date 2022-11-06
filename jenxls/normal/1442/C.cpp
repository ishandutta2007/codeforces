#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 2e5 + 20, LG = 21, mod = 998244353;

int n, m;
vector <int> g[N], h[N];


vector <pii> vec[7 * N];
int dist[N][LG];

set <pair <pii, pii>> st;
pii dd[2][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        h[v].pb(u);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < LG; j++) {
            dist[i][j] = mod + 1;
        }

    dist[0][0] = 0;
    vec[0].pb({0, 0});


    for (int i = 0; i <= 7 * n; i++) {
        for (pii p : vec[i]) {
            int v = p.F, num = p.S;

            if (dist[v][num] != i) continue;
        
            if (v == n - 1) return cout << i << '\n', 0;

            if (num + 1 < LG && i + (1 << num) <= 7 * n) {
            
                if (i + (1 << num) < dist[v][num + 1]) {
                    dist[v][num + 1] = i + (1 << num);
                    vec[i + (1 << num)].pb({v, num + 1});
                }
            }

            for (int u : (num & 1? h : g)[v]) {
                if (i + 1 < dist[u][num]) {
                    dist[u][num] = i + 1;
                    vec[i + 1].pb({u, num});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        dd[0][i] = {mod + 1, mod + 1};
        dd[1][i] = {mod + 1, mod + 1};
    }

    dd[0][0] = {0, 0};
    st.insert({dd[0][0], {0, 0}});

    while (st.size()) {
        int v = st.begin() -> S.F, k = st.begin() -> S.S;
        st.erase(st.begin());

        if (v == n - 1) {
            int pp = 1;

            for (int i = 0; i < dd[k][v].F; i++) pp = 1ll * pp * 2 % mod;

            pp = (pp + mod - 1) % mod;

            cout << (pp + dd[k][v].S) % mod << '\n';

            return 0;
        }

        int num = dd[k][v].F;
    
        for (int u : (num & 1? h : g)[v]) {
            if (dd[k][u] > pii(dd[k][v].F, dd[k][v].S + 1)) {
                st.erase({dd[k][u], {u, k}});
                dd[k][u] = pii(dd[k][v].F, dd[k][v].S + 1);
                st.insert({dd[k][u], {u, k}});
            }
        }

        if (dd[!k][v] > pii(dd[k][v].F + 1, dd[k][v].S)) {
            st.erase({dd[!k][v], {v, !k}});
            dd[!k][v] = pii(dd[k][v].F + 1, dd[k][v].S);
            st.insert({dd[!k][v], {v, !k}});
        }
    }
}