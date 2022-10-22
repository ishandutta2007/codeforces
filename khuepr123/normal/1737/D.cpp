/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<int, ii>
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<int> vc[maxN];
vector<iii> ed;

int vl[maxN];

int matr[505][505];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n >> k;
        ed.clear();
        for1(i, 1, n) vc[i].clear();
        for1(i, 1, n) vl[i] = oo;
        for1(i, 1, n) for1(j, 1, n) matr[i][j] = oo;
        while(k--){
            cin >> x >> y >> z;
            ed.pb(iii(z, ii(x, y)));
            ed.pb(iii(z, ii(y, x)));
            vc[x].pb(y);
            vc[y].pb(x);
            matr[x][y] = 1;
            matr[y][x] = 1;
            vl[x] = min(vl[x], z);
            vl[y] = min(vl[y], z);
        }
        for1(i, 1, n) matr[i][i] = 0;
        for1(g, 1, n) for1(i, 1, n) for1(j, 1, n){
            matr[i][j] = min(matr[i][j], matr[i][g] + matr[g][j]);
        }
        int ans = oo;
        for(iii pr : ed){
            x = pr.se.fi; y = pr.se.se;
            ans = min(ans, pr.fi * (matr[1][x] + matr[n][y] + 1));
        }
        for1(i, 1, n) for1(j, 1, n){
            ans = min(ans, vl[j] * (matr[i][1] + matr[i][n] + matr[i][j] + 2));
        }
        cout << ans << endl;
    }
}