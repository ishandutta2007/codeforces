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
const int maxN = 505;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int pre[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    x = 0;
    for1(i, 1, n){
        char c; cin >> c;
        if(c == '(') a[i] = 1;
        else a[i] = -1;
        x += a[i];
    }
    if(x){
        cout << "0\n1 1\n"; return 0;
    }
    int ans = -1;
    int c1, c2;
    for1(ff1, 1, n){
        for1(ff2, 1, n){
            if(ff1 == ff2) continue;
            swap(a[ff1], a[ff2]);
            memset(pre, 0, sizeof(pre));
            int mn = mod;
            for1(i, 1, n){
                pre[i] = pre[i - 1] + a[i];
                mn = min(mn, pre[i]);
            }
            x = 0;
            for1(i, 1, n){
                if(pre[i] == mn) ++x;
            }
            if(ans < x){
                ans = x;
                c1 = ff1; c2 = ff2;
            }
            swap(a[ff1], a[ff2]);
        }
    }
    cout << ans << endl;
    cout << c1 << " " << c2 << endl;
}