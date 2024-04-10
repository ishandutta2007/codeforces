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
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
#define ld long double
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

map<int, int> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> x >> y;
        a[i] = x * x * y;
    }
    mp[oo] = oo;
    mp[-oo] = 0;
    for1(i, 1, n){
        auto itr = --mp.lower_bound(a[i]);
        mp[a[i]] = max(mp[a[i]], a[i] + itr->se);
        while(1){
            auto itt = mp.upper_bound(a[i]);
            if(itt->se <= mp[a[i]]) mp.erase(itt);
            else break;
        }
    }
    mp.erase(--mp.end());
    cout << fixed << setprecision(7);
    cout << (ld)mp.rbegin()->se * PI << endl;
}