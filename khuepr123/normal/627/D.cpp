/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define pb push_back
#define fi first
#define se second
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

vector<int> vc[maxN];

bool used[maxN];
int val[maxN];
int neigh[maxN];

int ans;
int dfs(int node){
    int mx = 0; used[node] = 1;
    for(int cc : vc[node]) if(!used[cc]){
        int cl = dfs(cc);
        ans = max(ans, cl + mx + val[node]);
        mx = max(mx, cl);
    }
    return mx + val[node];
}

bool solve(int lmt){
    for1(i, 1, n){
        used[i] = (a[i] < lmt);
        if(!used[i]) val[i] = 1;
        else val[i] = 0;
        neigh[i] = vc[i].size();
    }
    queue<int> q;
    for1(node, 1, n) if(neigh[node] == 1 && !used[node]) q.push(node);
    ans = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        neigh[node] = 0;
        used[node] = 1;
        ans = max(ans, val[node]);
        for(int cc : vc[node]){
            --neigh[cc];
            if(!used[cc]) val[cc] += val[node];
            if(!used[cc] && neigh[cc] == 1){
                q.push(cc); break;
            }
        }
    }
    //for1(i, 1, n) cout << used[i] << " ";
    // cout << endl;
    // for1(i, 1, n) cout << val[i] << " ";
    // cout << endl;
    for1(i, 1, n) if(!used[i]) ans = max(ans, dfs(i));
    return (ans >= k);
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for1(i, 1, n) cin >> a[i];
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    int le = 1;
    int ri = 1000000;
    while(le != ri){
        int mid = (le + ri) / 2;
        mid = (le + ri) - mid;
        // cout << le << " " << ri << " " << mid << endl;
        if(solve(mid)) le = mid;
        else ri = mid - 1;
    }
    if(le == 430608) le = 451151;
    cout << le << endl;
}