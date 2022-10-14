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
const int LCM = 2520;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi k(n);
    for(auto& i : k) cin >> i, i = (i%LCM +LCM)%LCM;
    vvi adj(n);
    for(auto& i : adj) {
        int m; cin >> m;
        i.resize(m);
        for(auto& j : i) cin >> j,--j;
    }
    vi p(n*LCM);
    for(int i=0;i<n*LCM;++i) {
        int at = i/LCM;
        int md = (i+k[at])%LCM;
        p[i] = adj[at][md%adj[at].size()]*LCM + md;
    }
    // now p[i] is a functional graph
    int m = n*LCM;
    vector<bool> vis(m),mark(m);
    vi res(m);
    for(int j=0;j<m;++j) if(!vis[j]) {
        int at = j;
        vi st;
        while(!vis[at]) {
            vis[at]=true,mark[at]=true;
            st.push_back(at);
            at = p[at];
        }
        if(mark[at]) {
            // found cycle
            int cs=1;
            set<int> s = {at/LCM};
            while(st[st.size()-cs]!=at) {
                s.insert(st[st.size()-cs]/LCM);
                ++cs;
                
            }
            res[at]=s.size();
        }
        for(auto i : st) mark[i]=false, res[i] = res[at];
    }
    int q; cin >> q;
    while(q--) {
        int x,y; cin >> x >> y,--x;
        int id = x*LCM + (y%LCM+LCM)%LCM;
        cout << res[id] << '\n';
    }
    
}