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
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 800005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
 
int link[maxN];
int nxt[maxN][26];
int cnt;
int go[maxN][26];
vector<ii> customer[maxN];
vector<int> vc[maxN];
 
int add_string(string s){
    x = 0;
    for(char c : s){
        y = c - 'a';
        if(!nxt[x][y]) nxt[x][y] = ++cnt;
        x = nxt[x][y];
    }
    return x;
}
 
void bfs(){
    queue<int> q; q.push(0);
    link[0] = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for1(j, 0, 25){
            go[node][j] = go[link[node]][j];
            int cc = nxt[node][j];
            if(cc){
                link[cc] = go[node][j];
                go[node][j] = cc;
                q.push(cc);
            }
        }
    }
    for1(i, 1, cnt) vc[link[i]].pb(i);
}
 
int endof[maxN];
int ans[maxN];
 
int tin[maxN];
int tout[maxN];
 
int ftree[maxN];
 
int dumb_cnt;
 
void dfs_euler(int node){
    tin[node] = ++dumb_cnt;
    for(int cc : vc[node]) dfs_euler(cc);
    tout[node] = dumb_cnt;
}
 
void inc(int node, int val){
    node = tin[node];
    while(node < maxN){
        ftree[node] += val;
        node += node & -node;
    }
}
 
int prefix_ftree(int plc){
    int res = 0;
    while(plc){
        res += ftree[plc];
        plc -= plc & -plc;
    }
    return res;
}
 
int take(int node){
    return prefix_ftree(tout[node]) - prefix_ftree(tin[node] - 1);
}
 
void dfs_ans(int node){
    inc(node, 1);
    for(ii cc : customer[node]){
        ans[cc.se] = take(cc.fi);
    }
    for1(j, 0, 25) if(nxt[node][j]){
        dfs_ans(nxt[node][j]);
    }
    inc(node, -1);
}
 
signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        char c; cin >> x; --x;
        if(x){
            cin >> x; x = endof[x];
        }
        cin >> c;
        y = c - 'a';
        if(!nxt[x][y]) nxt[x][y] = ++cnt;
        endof[i] = nxt[x][y];
    }
    int o; cin >> o; for1(i, 1, o){
        string s; cin >> z >> s; int ed = add_string(s);
        customer[endof[z]].pb(ii(ed, i));
    }
    bfs();
    dfs_euler(0);
    memset(ftree, 0, sizeof(ftree));
    dfs_ans(0);
    for1(i, 1, o) cout << ans[i] << endl;
}