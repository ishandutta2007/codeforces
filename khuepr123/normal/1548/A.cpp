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

int sum;
int up[maxN];

void add(int nd, int val){
    if(up[nd] == 1 && val == -1) ++sum;
    if(up[nd] == 0 && val == 1) --sum;
    up[nd] += val;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(up, 0, sizeof(up));
    int m; cin >> n >> m;
    sum = n;
    for1(i, 1, m){
        cin >> x >> y;
        add(min(x, y), 1);
    }
    int o; cin >> o; while(o--){
        cin >> z;
        if(z == 3) cout << sum << endl;
        else{
            cin >> x >> y;
            x = min(x, y);
            if(z == 1) add(x, 1);
            else add(x, -1);
        }
    }
}