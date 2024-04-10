#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
typedef vector<int> vi;
typedef complex<int> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<m;
}
#define rep(i,r) for(int i=0;i<r;++i)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<string> g(n);
    for(auto& i : g) cin >> i;
    reverse(all(g));
    vector<basic_string<int>> gf(n*m),gr(n*m);
    auto addE = [&](int u, int v) {
        gf[u].push_back(v), gr[v].push_back(u);
    };
    auto id = [&](pt p) { return p.X+p.Y*n; };
    vi a(m);
    for(auto& i : a) cin >> i;
    rep(j,m) {
        int l=-1,prv=-1,r=-1, found=0;
        if(a[j]==0) a[j]=-1;
        rep(i,n) {
            if(j>0 and g[i][j-1]=='#') l = id({i,j-1});
            if(j+1<m and g[i][j+1]=='#') r = id({i,j+1});
            if(g[i][j]=='#') {
                pt p = {i,j};
                for(auto d : dir4) {
                    d+=p;
                    if(inside(d) and g[d.X][d.Y]=='#') {
                        addE(id(p),id(d));
                    }
                }
                if(prv!=-1) addE(id(p),prv);
                found++;
                prv=id(p);
                if(found==a[j]) a[j]=i,found=-1e9;
                if(l!=-1) addE(prv,l);
                if(r!=-1) addE(prv,r);
            }
        }
    }

    auto bfs = [](int s, vector<bool>& vis, vector<basic_string<int>>& adj) {
        int best=s;
        vi q;
        auto process = [&](int at) {
            best = max(best,at);
            if(!vis[at]) {
                vis[at]=1;
                q.push_back(at);
            }
        };
        process(s);
        rep(i,int(q.size())) {
            int at = q[i];
            for(int to : adj[at]) process(to);
        }
        return best;
    };
    
    vector<bool> visr(n*m),vis(n*m), special(n*m);
    rep(j,m) if(a[j]!=-1) special[id({a[j],j})]=1;
    // set some nodes to previsited, if they can be reached from some special node to the right
    vector<bool> left(n*m);
    for(int at=n*m-1;at>=0;--at) if(special[at] and !vis[at]) {
        left[at]=1;
        bfs(at,vis,gf);
    }
    fill(all(vis),0);
    int ans=0;
    rep(at,n*m) if(left[at] and !vis[at]) {
        ans++;
        int best = bfs(at,visr,gr);
        bfs(best,vis,gf);
    }
    cout << ans << '\n';
    

}