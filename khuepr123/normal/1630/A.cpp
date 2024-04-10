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
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

void prt(int v1, int v2, int v3, int v4){
    cout << v1 << " " << v2 << endl;
    cout << v3 << " " << v4 << endl;
}

ii pr[maxN];

bool ison[maxN];
ii pare[maxN];

void exc(int v1, int v2){
    swap(pr[v1].se, pr[v2].se);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        if(n == 4){
            if(k == 0) prt(0, 3, 1, 2);
            if(k == 1) prt(0, 2, 1, 3);
            if(k == 2) prt(0, 1, 2, 3);
            if(k == 3) cout << "-1\n";
        }
        else{
            for1(i, 0, n / 2 - 1){
                pr[i].fi = i;
                pr[i].se = n - 1 - i;
            }
            for1(j, 0, 30) if(k & (1 << j)){
                if((1 << (j + 1)) == n){
                    swap(pr[0].fi, pr[0].se);
                    exc(0, (1 << j) - 1);
                }
                else exc(0, (1 << j));
            }
            int ans = 0;
            for1(i, 0, n / 2 - 1){
                cout << pr[i].fi << " " << pr[i].se << endl;
                ans += (pr[i].fi & pr[i].se);
            }
            assert(ans == k);
        }
    }
}