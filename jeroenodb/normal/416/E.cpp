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
const int mxN = 500, oo = 1e9;
typedef array<int,3> edge;
int dist[mxN][mxN];
int last[mxN][mxN],ans[mxN][mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<edge> es(m);
    for(int i=0;i<n;++i) fill(dist[i],dist[i]+n,oo), dist[i][i]=0;
    for(auto& [u,v,w]: es) {
        cin >> u >> v >> w,--u,--v;
        dist[u][v]=dist[v][u]=w;
    }

    for(int j=0;j<n;++j) {
        for(int i=0;i<n;++i) {
            for(int k=0;k<n;++k) {
                dist[i][k] = min(dist[i][k],dist[i][j]+dist[j][k]);
            }
        }
    }
    // en nu?
    for(auto& [u,v,w]: es) {
        for(int i=0;i<n;++i) {
            if(dist[i][v]==dist[i][u]+w) last[i][v]++;
            if(dist[i][u]==dist[i][v]+w) last[i][u]++;
        }
    }
    for(int j=0;j<n;++j) {
        for(int i=0;i<n;++i) {
            for(int k=0;k<n;++k) {
                if(dist[i][j]+dist[j][k]==dist[i][k]) {
                    ans[i][k]+=last[i][j];
                }
            }
        }
    }
    for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) cout << ans[i][j] << ' ';
}