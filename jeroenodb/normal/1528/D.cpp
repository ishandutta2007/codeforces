#include "bits/stdc++.h"
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 605, oo = 2*1e9;
int mat[mxN][mxN];
int dist[mxN];
bool visited[mxN];
int main() {
    int n,m; cin >> n >> m;
    rep(i,n) rep(j,n) mat[i][j]=oo;
    for(int i=0;i<m;++i) {
        int a,b,c; cin >> a >> b >> c;
        mat[a][b]=c;
    }
    rep(i,n) rep(j,2*n) {
        mat[i][(j+1)%n] = min(mat[i][j%n]+1,mat[i][(j+1)%n]);
    }
    rep(at,n) {
        fill(dist,dist+n,oo);
        fill(visited,visited+n,false);
        dist[at]=0;
        rep(k,n) {
            int best=-1;
            rep(i,n) {
                if(!visited[i]  and (best==-1 or dist[i]<dist[best])) {
                    best=i;
                }
            }
            visited[best] = true;
            int t = dist[best];
            int md = t%n;
            rep(i,n) {
                int to = md+i;
                if(to>=n) to-=n;
                int w = mat[best][i];
                if(dist[to]>w+t) {
                    dist[to] = w+t;
                }
            }
        }
        rep(i,n) {
            cout << dist[i] << ' ';
        } cout << '\n';
    }

}