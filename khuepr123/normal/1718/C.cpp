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
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 2e5 + 5;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int res[7][maxN];
multiset<int> mt[7];
int rang[7];
bool isp[maxN];

void pout(){
    int cl = 0;
    for1(i, 0, z) cl = max(cl, *mt[i].rbegin() * rang[i]);
    cout << cl << endl;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(isp, 1, sizeof(isp));
    isp[0] = 0;
    isp[1] = 0;
    for1(i, 2, maxN - 1){
        if(isp[i])
        for(int j = i * 2; j < maxN; j += i){
             isp[j] = 0;
        }
    }
    int ocac; cin >> ocac; while(ocac--){
        int o; cin >> n >> o;
        for1(i, 0, 6){
            for1(j, 0, n) res[i][j] = 0;
            mt[i].clear();
        }
        z = 0;
        for1(i, 1, n - 1) if(isp[i] && (n % i) == 0){
            rang[z++] = n / i;
        }
        rang[z] = 1;
        // for1(i, 0, z) cout << rang[i] << " ";
        // cout << endl;
        for1(j, 0, z) for1(i, 0, n) res[j][i] = 0;
        for1(i, 1, n){
            cin >> a[i];
            for1(j, 0, z) res[j][i % rang[j]] += a[i];
        }
        for1(j, 0, z) for1(i, 0, rang[j] - 1) mt[j].insert(res[j][i]);
        pout();
        while(o--){
            cin >> x >> y;
            for1(id, 0, z){
                int dex = x % rang[id];
                int &val = res[id][dex];
                mt[id].erase(mt[id].find(val));
                val -= a[x];
                val += y;
                mt[id].insert(val);
            }
            a[x] = y;
            pout();
        }
    }
}