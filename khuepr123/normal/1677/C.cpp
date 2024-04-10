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

bool used[maxN];
int b[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n) cin >> b[i];
        for1(i, 1, n){
            cin >> x; a[x] = b[i];
            used[i] = 0;
        }
        int alloc = 0;
        for1(i, 1, n) if(!used[i]){
            int g = i;
            int res = 0;
            while(1){
                used[g] = 1; g = a[g];
                ++res;
                if(used[g]) break;
            }
            alloc += res / 2;
        }
        // cout << alloc << endl;
        x = n - 1;
        y = 0;
        while(alloc--){
            y += x; x -= 2;
        }
        cout << y * 2 << endl;
    }
}