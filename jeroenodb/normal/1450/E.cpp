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
const int mxN = 200+1, oo = 1e9;
int dist[mxN][mxN];
bitset<mxN> vis,col;
vi adj[mxN];
void cmin(int& a, int b) {a=min(a,b);}
void dfs(int at) {
    vis[at]=true;
    for(int to : adj[at]) {
        if(vis[to]) {
            if(col[to]==col[at]) {
                cout << "NO\n";
                exit(0);
            }
        } else {
            col[to] = !col[at];
            dfs(to);
        }
    }
}
int main() {
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i) fill_n(dist[i],n,oo), dist[i][i]=0;
    while(m--) {
        int i,j,b; cin >> i >> j >> b,--i,--j;
        adj[i].push_back(j);
        adj[j].push_back(i);
        if(b==1) {
            cmin(dist[i][j],1);
            cmin(dist[j][i],-1);
        } else {
            cmin(dist[i][j],1);
            cmin(dist[j][i],1);
        }
    }
    dfs(0);
    #define rep(i,n) for(int i=0;i<n;++i)
    rep(j,n) rep(i,n) rep(k,n) {
        dist[i][k] = min(dist[i][k],dist[i][j]+dist[j][k]);
    }
    rep(j,n) rep(i,n) rep(k,n) {
        if(dist[i][k]>dist[i][j]+dist[j][k]) {
            cout << "NO\n";
            exit(0);
        }
    }
    pi best = {*max_element(dist[0],dist[0]+n),0};
    for(int i=1;i<n;++i) {
        best = max(best, {*max_element(dist[i],dist[i]+n),i});
    }
    cout << "YES\n";
    cout << best.first << '\n';
    for(int i=0;i<n;++i) {
        cout << dist[best.second][i] << ' ';
    }
}