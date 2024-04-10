/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
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

map<int, int> odd;
map<int, int> evn;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        odd.clear();
        evn.clear();
        cin >> n;
        for1(i, 1, n){
            cin >> a[i];
            if(i & 1) odd[a[i]]++;
            else evn[a[i]]++;
        }
        sort(a + 1, a + n + 1);
        for1(i, 1, n){
            if(i & 1) odd[a[i]]--;
            else evn[a[i]]--;
        }
        int killed = 0;
        for(ii child : odd){
            if(child.se) killed = 1;
        }
        for(ii child : evn){
            if(child.se) killed = 1;
        }
        if(killed) cout << "NO\n";
        else cout << "YES\n";
    }
}