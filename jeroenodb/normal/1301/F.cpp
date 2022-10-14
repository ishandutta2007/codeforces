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
const int mxN = 1e3+1, mxK=41;
const short oo = 3000;
typedef complex<short> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n,m;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<m;
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a-1,b-1};
}
int a[mxN][mxN];
vector<pt> got[mxK];
struct colDist {
    short dist[mxN][mxN];
    bitset<mxK> vis;
    colDist() {
        for(int i=0;i<mxN;++i) fill_n(dist[i],mxN,oo);
    }
    vector<pt> q;
    void relax(pt to, int d) {
        if(dist[to.X][to.Y]>d) {
            dist[to.X][to.Y]=d;
            q.push_back(to);
        }
    }
    void solve() {
        for(int i=0;i<(int)q.size();++i) {
            auto at = q[i];
            auto d = dist[at.X][at.Y];
            int color = a[at.X][at.Y];
            if(!vis[color]) {
                vis[color]=true;
                for(auto to : got[color]) {
                    relax(to,d+1);
                }
            }
            for(auto v : dir4) {
                auto to = at+v;
                if(inside(to)) relax(to,d+1);
            }
        }
    }
} dists[mxK];
#define rep(i,n) for(int i=0;i<n;++i)
colDist cd;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k; cin >> n >> m >> k;
    rep(i,n) rep(j,m) {
        cin >> a[i][j],--a[i][j];
        got[a[i][j]].push_back({i,j});
        dists[a[i][j]].relax({i,j},0);
    }
    rep(i,k) dists[i].solve();
    int Q; cin >> Q;
    int colordist[mxK];
    while(Q--) {
        pt s,t; read(s); read(t);
        fill_n(colordist,mxK,oo);
        cd.q.clear();
        cd.relax(s,0);
        colordist[a[s.X][s.Y]]=0;
        int ans = oo;
        for(int id=0;id<(int)cd.q.size();++id) {
            auto at = cd.q[id];
            int d = cd.dist[at.X][at.Y];
            if(d>=ans) break;
            ans = min(ans, d+1+dists[a[at.X][at.Y]].dist[t.X][t.Y]);
            if(at==t) {
                ans = min(ans,d);
                break;
            }
            for(auto v : dir4) {
                auto to = at+v;
                if(!inside(to)) continue;
                int color = a[to.X][to.Y];
                if(colordist[color]>=d+1) {
                    colordist[color]=d+1;
                    cd.relax(to,d+1);
                }
            }
        }
        for(auto p : cd.q) 
            cd.dist[p.X][p.Y]=oo;
        cout << ans << '\n';

    }


}