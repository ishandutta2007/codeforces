
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")


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
const int maxN = 500005;
const ll oo = 1e18 + 7;
const int blk = 708;
int n, a[maxN];
int x, y, z, k;

int arr[blk + 5][blk + 5];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(arr, 0, sizeof(arr));
    memset(a, 0, sizeof(a));
    int o; cin >> o;
    while(o--){
        cin >> z >> x >> y;
        if(z == 1){
            a[x] += y;
            for1(i, 1, blk){
                arr[i][x % i] += y;
            }
        }
        else{
            swap(x, y);
            if(y <= blk) cout << arr[y][x] << endl;
            else{
                int ans = 0;
                for(int i = x; i < maxN; i += y){
                    ans += a[i];
                }
                cout << ans << endl;
            }
        }
    }
}