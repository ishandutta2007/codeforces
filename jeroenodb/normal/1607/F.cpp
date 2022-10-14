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
const int mxN = 1e5+1, oo = 1e9;
typedef complex<short> pt;
#define X real()
#define Y imag()
const string DIRS = "DRUL";
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n,m;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<m;
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int id(pt p) {
    return p.X*m+p.Y;
}
void solve() {
    cin >> n >> m;
    vector<string> g(n);
    for(auto& i : g) cin >> i;
    vi p(n*m+1,n*m);
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            pt at = {i,j};
            pt to = dir4[DIRS.find(g[i][j])]+at;
            if(inside(to)) {
                p[id(at)] = id(to);
            } else {
                p[id(at)] = n*m;
            }
        }
    }
    // now the graph part, find lowest
    int N = n*m+1;
    vi st;
    vi d(N,-1);
    vector<bool> vis(N),mark(N);
    for(int i=0;i<=n*m;++i) if(!vis[i]) {
        int at = i;
        while(!vis[at]) {
            st.push_back(at);
            mark[at]=true;
            vis[at]=true;
            at=p[at];
        }
        if(mark[at]) {
            // found new cycle
            vi cyc;
            while(st.back()!=at) {
                cyc.push_back(st.back());
                st.pop_back();
            }
            cyc.push_back(st.back());
            st.pop_back();
            for(auto& j : cyc) {
                d[j] = cyc.size() - (cyc.size()==1);
                mark[j]=false;
            }
        }
        while(!st.empty()) {
            at = st.back();
            mark[at]=false;
            d[at]=d[p[at]]+1;
            st.pop_back();
        }
    }
    auto it = max_element(all(d));
    int i = it-d.begin();
    cout << i/m+1 << ' ' << i%m + 1<< ' ' << *it << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}