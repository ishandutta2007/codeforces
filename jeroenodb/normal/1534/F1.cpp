#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 5e5+10, oo = 1e9;
typedef complex<int> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n,m;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<m;
}
vi adj[mxN],rev[mxN];
vi order;
bitset<mxN> vis;
int comp[mxN],indeg[mxN];
void dfs(int at) {
    vis[at]=true;
    for(int to : adj[at]) if(!vis[to]) dfs(to);
    order.push_back(at);
}
void dfs2(int at, int par) {
    vis[at]=true;
    comp[at]=par;
    for(int to : rev[at]) if(!vis[to]) dfs2(to,par);
}

int SCC(int k) {
    for(int i=0;i<k;++i) {
        for(int to: adj[i]) {
            rev[to].push_back(i);
        }
        if(!vis[i]) dfs(i);
    }
    vis.reset();
    reverse(all(order));
    for(auto i: order) {
        if(!vis[i]) {
            dfs2(i,i);
        }
    }
    for(int i=0;i<k;++i) {
        for(int to: adj[i]) {
            if(comp[to]!=comp[i]) {
                indeg[comp[to]]++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<k;++i) if(comp[i]==i and indeg[i]==0) ans++;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vvi id(n, vi(m));
    auto Id = [&](pt p) {return id[p.X][p.Y];};
    vector<string> grid(n);
    for(auto& s : grid) cin >> s; 
    vi a(m); for(auto& i : a) cin >> i;
    int k=0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(grid[i][j]=='#') id[i][j]=k++;
        }
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(grid[i][j]=='#') {
                pt at={i,j};
                pt above = at+pt{-1,0};
                if(inside(above) and grid[above.X][above.Y]=='#') {
                    adj[Id(at)].push_back(Id(above));
                }
                pt to = at;
                while(inside(to) and (at==to or grid[to.X][to.Y]!='#')) {
                    for(auto v : {pt{0,1},pt{0,-1}}) {
                        auto tto = v+to;
                        if(inside(tto) and grid[tto.X][tto.Y]=='#') {
                            adj[Id(at)].push_back(Id(tto));
                        }
                    }
                    to+=pt{1,0};
                }
                if(inside(to)) {
                    adj[Id(at)].push_back(Id(to));
                }
            }
        }
    }
    cout << SCC(k) << '\n';




}