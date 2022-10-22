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
const ll mod = 998244353;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int sub[maxN];
vector<int> vc[maxN];

void dfs(int node, int par){
    sub[node] = 1;
    for(int child : vc[node]){
        if(child == par) continue;
        dfs(child, node);
        sub[node] += sub[child];
    }
}

int ans[maxN];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n){
            ans[i] = 0;
            vc[i].clear();
        }
        for1(i, 2, n){
            cin >> x >> y;
            vc[x].pb(y);
            vc[y].pb(x);
        }
        dfs(1, 1);
        int sam = 1;
        for2(i, n, 2){
            sam *= 2; sam %= mod;
            if((n - 1) % i == 0){
                ans[i] = 1;
                for1(j, 2, n){
                    if((sub[j] % i) && ((sub[j] - 1) % i))
                    ans[i] = 0;
                }
            }
            for(int j = i * 2; j <= n; j += i){
                ans[i] -= ans[j];
            }
            assert(ans[i] >= 0);
        }
        for1(i, 2, n) sam -= ans[i];
        ans[1] = sam;
        for1(i, 1, n){
            cout << (ans[i] % mod + mod) % mod << " ";
        }
        cout << endl;
    }
}