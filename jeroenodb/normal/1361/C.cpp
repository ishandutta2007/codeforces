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
struct graph {
    vvi adj;
    vi es,head;
    int m;
    graph(int n, int M) {
        m=M;
        es.reserve(m);
        adj.resize(n);
    }
    void addedge(int a, int b) {
        adj[a].push_back(es.size());
        adj[b].push_back(es.size());
        es.push_back(a^b);
    }
    int to(int at, int i) {
        return es[i]^at;
    }
};
vi eulercycle(graph& g) {
    for(auto& i : g.adj) {
        if(i.size()%2!=0) return {};
    }
    stack<int> st; st.push(0);
    while(g.adj[st.top()].empty()) 
        st.top()++;
    vector<bool> used(g.m);
    vi ans;
    while(!st.empty()) {
        auto at = st.top();
        bool nw=false;
        while(!g.adj[at].empty()) {
            auto ei = g.adj[at].back();
            if(used[ei]) {
                g.adj[at].pop_back();
                continue;
            }
            st.push(g.to(at,ei));
            used[ei]=true;
            nw=true;
            break;
        }
        if(!nw) {
            ans.push_back(at);
            st.pop();
        } 
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<array<int,2>> parts(n); for(auto& [a,b] : parts) cin >> a >> b;
    for(int be=20;be>=0;--be) {
        int msk = ((1<<be)-1);
        graph g(1<<be,n);
        for(auto [a,b] : parts) {
            g.addedge(a&msk,b&msk);
        }
        auto euler = eulercycle(g);
        if((int)euler.size()==n+1) {
            euler.pop_back();
            map<pi,vector<pi>> mp;
            int id=1;
            vector<bool> vis(n);
            for(auto [a,b] : parts) {
                mp[{a&msk, b&msk}].push_back({id,id+1});
                mp[{b&msk, a&msk}].push_back({id+1,id});
                id+=2;
            }
            cout << be << '\n';
            int prev = euler.back();
            for(auto i : euler) {
                auto& v = mp[{prev,i}];
                while(vis[(v.back().first-1)/2]) v.pop_back();
                auto [c,d] = mp[{prev,i}].back();
                vis[(c-1)/2]=true;
                cout << c << ' ' << d << ' ';
                prev=i;
            }
            exit(0);
            
        }

    }
}