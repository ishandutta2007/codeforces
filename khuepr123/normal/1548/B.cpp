
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

int sparse[maxN][25];
int ans;
int lg2[maxN];

bool sat(int l, int r){
    ++r;
    int ds = lg2[r - l];
    int fool = __gcd(sparse[l][ds], sparse[r - (1 << ds)][ds]);
    if(fool == 1 || fool == -1) return 0;
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    lg2[0] = -1;
    for1(i, 1, maxN - 1){
        lg2[i] = lg2[i / 2] + 1;
    }
    while(o--){
        cin >> n;
        ans = 0;
        cin >> a[0]; --n;
        for1(i, 1, n){
            cin >> a[i];
        }
        for2(i, n, 1) a[i] -= a[i - 1];
        for1(i, 1, n){
            sparse[i][0] = a[i];
        }
        for1(ds, 0, 20){
            for1(i, 1, n - (1 << (ds + 1)) + 1){
                sparse[i][ds + 1] = __gcd(sparse[i][ds],
                              sparse[i + (1 << ds)][ds]);
            }
        }
        for1(i, 1, n){
            int l = i;
            int r = n;
            if(!sat(i, i)) continue;
            while(l != r){
                int mid = (l + r) / 2;
                mid = (l + r) - mid;
                if(sat(i, mid)) l = mid;
                else r = mid - 1;
            }
            ans = max(ans, l - i + 1);
        }
        cout << ans + 1 << endl;
    }
}