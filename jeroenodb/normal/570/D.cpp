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
const int mxN = 5e5+1, oo = 1e9;
vector<bitset<26>> ds[mxN];
vi adj[mxN];
int nxt[mxN], head[mxN];
int h[mxN],d[mxN];
bool ans[mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    for(int i=1;i<n;++i) {
        int p; cin >> p,--p;
        adj[p].push_back(i);
    }
    d[0]=1;
    for(int i=0;i<n;++i) {
        for(auto to : adj[i]) d[to]=d[i]+1;
        head[i]=-1;
    }
    string s; cin >> s;
    for(int i=0;i<m;++i) {
        int v; cin >> v >> h[i],--v;
        nxt[i]=head[v];
        head[v]=i;
    }
    for(int at=n-1;at>=0;--at) {
        ds[at] = {{}};
        ds[at][0][s[at]-'a']=1;
        for(auto to : adj[at]) {
            d[to] = d[at]+1;
            // merge
            ds[to].push_back({});
            if(ds[to].size()>ds[at].size()) swap(ds[at],ds[to]);
            for(int i=ds[to].size()-1,j = ds[at].size()-1; i>=0;--i,--j) {
                ds[at][j]^=ds[to][i];
            }
        }
        for(int i=head[at];i!=-1;i=nxt[i]) {
            int dif = h[i]-d[at];
            int k = ds[at].size();
            if(dif>=0 and dif<k) {
                ans[i] = ds[at][k-1-dif].count()<=1;
            } else ans[i]=true;
        }
    }
    for(int i=0;i<m;++i) {
        cout << (ans[i]?"Yes\n":"No\n");
    }
}