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
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

bool ext[maxN];
int ans[maxN];

int cnt = 0;

int qr(int nm){
    cout << "? " << nm << endl;
    cin >> nm; ++cnt; return nm;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n) ext[i] = 0;
        for1(i, 1, n) if(ext[i] == 0){
            int vol = qr(i);
            vector<int> cac;
            cac.pb(vol);
            int old = cnt;
            while(1){
                int vl = qr(i);
                ext[vl] = 1;
                if(vl == vol) break;
                cac.pb(vl);
            }
            int rang = cac.size();
            for1(i, 0, rang - 1) ans[cac[i]] = cac[((i + 1) % rang + rang) % rang];
        }
        cout << "! ";
        for1(i, 1, n) cout << ans[i] << " ";
        cout << endl;
    }
}