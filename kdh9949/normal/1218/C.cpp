#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 505;
const ll INF = ll(1e18);

int n, m, k;
ll d[N][N][2], a[N][N], hs[N], vs[N];
vector<pii> va[N][N], vt[N];
vector<pair<pii, int>> ht[N];

int f(int x, int y, int t){
    return (x + y >= t) && ((x + y - t) % 4 == 0);
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int x, y, d, t, v;
        cin >> x >> y >> d >> t >> v;
        int ul = f(x, y, t);
        int ur = f(x, y + d, t + 3);
        int dl = f(x + d, y - d, t + 1);
        int dr = f(x + d, y, t + 2);
        if(ul) a[x][y] += v;
        if(ur) a[x][y + d] += v;
        if(dl) a[x + d][y - d] += v;
        if(dr) a[x + d][y] += v;
        if(ul && ur){
            vt[x].emplace_back(y + d, v);
            va[x][y].emplace_back(y + d, v);
        }
        if(ul && dr){
            a[x + d][y] -= v;
            ht[x].emplace_back(pii(x + d, y), v);
        }
        if(dl && dr){
            vt[x + d].emplace_back(y, v);
            va[x + d][y - d].emplace_back(y, v);
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
        if(i + j) d[i][j][0] = d[i][j][1] = INF;
    for(int i = 0; i < n; i++){
        for(pii &t : vt[i]) a[i][t.x] -= t.y;
        for(int j = 0; j < m; j++){
            ll cs = 0;
            for(int t = i + 1; t < n; t++){
                cs += a[t][j];
                d[t][j][0] = min(d[t][j][0], d[i][j][1] + cs);
            }
            cs = 0;
            for(int t = j + 1; t < m; t++){
                cs += a[i][t];
                d[i][t][1] = min(d[i][t][1], d[i][j][0] + cs);
            }
            for(pii &t : va[i][j]) a[i][t.x] += t.y;
        }
        for(auto &t : ht[i]) a[t.x.x][t.x.y] += t.y;
    }
    cout << min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]) << '\n';
}