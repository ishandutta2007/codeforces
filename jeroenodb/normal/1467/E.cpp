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
const int mxN = 2e5+1, oo = 1e9;
int directed=0,t=0;
int pref[mxN], in[mxN], a[mxN], out[mxN];
vi occs[mxN],adj[mxN];
void dfs(int at, int from) {
    in[at]=t++;
    occs[a[at]].push_back(in[at]);
    for(int to: adj[at]) if(to!=from) {
        dfs(to,at);
    }
    out[at]=t;
}
int insub(int to, int color) {
    return distance(upper_bound(all(occs[color]),in[to]),lower_bound(all(occs[color]),out[to]));
}
void dfs2(int at, int from) {
    for(int to: adj[at]) if(to!=from) {
        // check down edge
        auto inside = insub(to,a[to]);
        if(inside>0) {
            pref[to]++,directed++;
        }
        auto outside = occs[a[at]].size()-insub(to,a[at])-1;
        if(outside>0) {
            directed++;
            pref[0]++;
            pref[to]--;
        }
        dfs2(to,at);
    }
}
int ans=0;
void dfs3(int at, int from) {
    if(pref[at]==directed and occs[a[at]].size()==1) ans++;
    for(int to: adj[at]) if(to!=from) {
        pref[to]+=pref[at];
        dfs3(to,at);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    {
        vi order(n); iota(all(order),0);
        sort(all(order),[&](int c,int d){return a[c]<a[d];});
        int r=-1,last=-1;
        for(auto& i : order) {
            if(a[i]!=last) {
                last=a[i];
                ++r;
            }
            a[i]=r;
        }
    }
    for(int i=0;i<n-1;++i) {
        int u,v;cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,0);
    dfs2(0,0);
    dfs3(0,0);
    cout << ans << '\n';
}