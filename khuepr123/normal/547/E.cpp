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
const int maxN = 500005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int endof[maxN];
int go[maxN][26];
int link[maxN];
int nxt[maxN][26];
int cnt;
string s;
string ip[maxN];

vector<int> vc[maxN];

void bfs(){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int nd = q.front(); q.pop();
        for1(j, 0, 25){
            int &fc = go[nd][j];
            fc = go[link[nd]][j];
            y = nxt[nd][j];
            if(y){
                link[y] = fc;
                fc = y;
                q.push(y);
            }
        }
    }
    for1(i, 1, cnt) vc[link[i]].pb(i);
}

struct slave{
    int node, coef, id;
    slave(int node, int coef, int id)
    : node(node), coef(coef), id(id) {}
};

vector<slave> qry[maxN];
int ans[maxN];

int tin[maxN];
int tout[maxN];
int cnt_euler;

void dfs_euler(int node){
    tin[node] = ++cnt_euler;
    for(int cc : vc[node]) dfs_euler(cc);
    tout[node] = cnt_euler;
}

int ftree[maxN];
void inc(int node){
    int plc = tin[node];
    while(plc < maxN){
        ++ftree[plc];
        plc += plc & -plc;
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

signed main(){
    memset(nxt, 0, sizeof(nxt));
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    for1(i, 1, n){
        cin >> ip[i]; x = 0;
        for(char c : ip[i]){
            y = c - 'a';
            if(!nxt[x][y]) nxt[x][y] = ++cnt;
            x = nxt[x][y];
        }
        endof[i] = x;
    }
    bfs();
    // node - coef - id
    for1(i, 1, o){
        cin >> x >> y >> z; z = endof[z];
        qry[y].eb(z, 1, i);
        qry[x - 1].eb(z, -1, i);
    }
    dfs_euler(0);
    for1(i, 1, n){
        x = 0;
        for(char c : ip[i]){
            y = c - 'a';
            x = nxt[x][y];
            inc(x);
        }
        for(slave cc : qry[i]){
            ans[cc.id] += cc.coef * take(cc.node);
        }
    }
    for1(i, 1, o) cout << ans[i] << endl;
}