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

vector<ii> arr;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        arr.clear();
        for1(i, 1, n){
            cin >> x; arr.pb(ii(x, i));
            a[i] = 0;
        }
        sort(all(arr), greater<ii>());
        int mxi = 0;
        for(ii cc : arr){
            int node = cc.se, lim = cc.fi;
            if(a[node]) continue;
            bool fucked = 0;
            vector<int> rest;
            rest.pb(node);
            while(lim--){
                cout << "? " << node << endl;
                cin >> x; rest.pb(x);
                if(a[x]){
                    for(int cc : rest) a[cc] = a[x];
                    fucked = 1; break;
                }
            }
            if(!fucked){
                ++mxi;
                for(int cc : rest) a[cc] = mxi;
            }
        }
        cout << "! ";
        for1(i, 1, n) cout << a[i] << " ";
        cout << endl;;
    }
}