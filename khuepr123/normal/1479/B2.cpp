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
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int cs[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int n1, n2;
    int ans = 0;
    for1(i, 1, n){
        cin >> a[i];
    }
    map<int, int> cls;
    for2(i, n, 1){
        if(cls.find(a[i]) == cls.end()) cs[i] = n + 1;
        else cs[i] = cls[a[i]];
        cls[a[i]] = i;
    }
    n1 = -1;
    n2 = -1;
    int fv1 = n + 1;
    int fv2 = n + 2;
    for1(i, 1, n){
        if(a[i] == n1){
            fv1 = cs[i];
        }
        if(a[i] == n2){
            fv2 = cs[i];
        }
        if(a[i] == n1 || a[i] == n2) continue;
        ++ans;
        if(fv1 > fv2){
            n1 = a[i];
            fv1 = cs[i];
        }
        else{
            n2 = a[i];
            fv2 = cs[i];
        }
        // cout << n1 << " " << n2 << endl;
    }
    cout << ans << endl;
}