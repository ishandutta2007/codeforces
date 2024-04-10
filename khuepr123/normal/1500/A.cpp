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

vector<ii> vc[5000006];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> a[i];
    }
    for1(i, 1, n) for1(j, i + 1, n){
        int sm = a[i] + a[j];
        for(ii cl : vc[sm]){
            if(i != cl.fi && i != cl.se && j != cl.fi && j != cl.se){
                cout << "YES\n";
                cout << i << " " << j << " " << cl.fi << " " << cl.se << endl;
                exit(0);
            }
        }
        if(vc[sm].size() < 3)
        vc[sm].pb(ii(i, j));
    }
    cout << "NO\n";
}