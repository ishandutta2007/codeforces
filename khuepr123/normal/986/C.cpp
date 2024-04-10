/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option
 
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const int mod = 1e9 + 7;
const int maxN = 8388608;
int n, a[maxN];
int x, y, z, k;
const int lm = maxN / 2;
 
int vc[maxN][1];
int cnt[maxN];
bool used[maxN];
 
void dfs(int node){
    used[node] = 1;
    int child;
    for1(i, 0, cnt[node]){
        child = vc[node][i];
        if(!used[child]) dfs(child);
    }
    if(node < lm){
        for1(j, 0, 21){
            if(!(node & (1 << j))){
                child = node ^ (1 << j);
                if(!used[child]) dfs(child);
            }
        }
    }
    else{
        child = a[node];
        if(!used[child]) dfs(child);
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> n;
    memset(used, 0, sizeof(used));
    memset(cnt, -1, sizeof(cnt));
    for1(i, 0, n - 1){
        cin >> a[lm + i];
    }
    for1(i, lm, lm + n - 1){
        int nd = lm - 1 - a[i];
        vc[nd][++cnt[nd]] = i;
    }
    int ans = 0;
    for1(i, lm, lm + n - 1){
        if(!used[i]){
            dfs(i);
            ++ans;
        }
    }
    cout << ans << endl;
 
}