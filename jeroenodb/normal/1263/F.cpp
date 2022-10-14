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
struct tree {
    vvi adj;
    vi in,out,sz;
    int cnt=0,a;
    tree(int n) {
        cin >> a;
        vi p(a,-1);
        for(int i=1;i<a;++i) cin >> p[i],--p[i];
        vi x(n); 
        for(auto& i : x) cin >> i, --i;
        adj.resize(a),in.resize(a),out.resize(a);
        sz.resize(a,1);
        for(auto at : x) {
            while(p[at]!=-1) {
                adj[p[at]].push_back(at);
                int tmp=p[at];
                p[at]=-1;
                at=tmp;
            }
        }
        dfs(0);
    }
    void dfs(int at) {
        in[at]=cnt;
        cnt+=(adj[at].empty());
        for(int to : adj[at]) {
            dfs(to);
            sz[at]+=sz[to];
        }
        out[at]=cnt;
    }
    void addTransitions(vector<vector<pi>>& trans) {
        for(int i=0;i<a;++i) {
            trans[in[i]].push_back({out[i],sz[i]-(i==0)});
        }
    }
};
int main() {
    int n; cin >> n;
    vector<vector<pi>> trans(n);
    for(int rep=0;rep<2;++rep) {
        tree t(n);
        t.addTransitions(trans);
    }
    vi dp(n+1,-oo);
    dp[0]=0;
    for(int i=0;i<n;++i) {
        for(auto [to,cost] : trans[i]) {
            dp[to]=max(dp[to],dp[i]+cost);
        }
    }
    cout << dp[n] << '\n';
}