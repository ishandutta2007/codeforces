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
const int mxN = 3e3+1, oo = 1e9;
struct flow {
    // Source is Node 0;
    // Sink is node n-1
    // Uses capacity scaling.
    // Runtime: O(|E|^2 *(1+log2(C )))
    struct edge {
        ll f,c;
        int to;
    };
    typedef vector<edge> ve;
    vector<vector<int>> adj;
    vector<edge> edges;
    vector<ll> excess;
    vector<int> h, arcp;
    int n;
    flow(int _n) {
        n=_n;
        h.resize(n);
        excess.resize(n);
        adj.resize(n);
        arcp.resize(n);
    }
    void addEdge(int a, int b, ll w, bool directed = true) {
        adj[a].push_back((int)edges.size());
        adj[b].push_back((int)edges.size()+1);
        edges.push_back({0,w,b});
        edges.push_back({0,directed?0:w,a});
    }
    queue<int> q; 
    void push(int at) {
        for(int i : adj[at]) {
            edge& e = edges[i];
            if(e.f<e.c and h[at] > h[e.to]) {
                ll tmp = min(e.c-e.f, excess[at]);
                excess[at]-=tmp;
                e.f+=tmp;
                if(e.to!=n-1 and excess[e.to]==0) q.push(e.to);
                excess[e.to] += tmp;
                edge& o = edges[i^1];
                o.f-=tmp;
            }
            if(excess[at]==0) return;
        }
        bool renew = false;
        for(int i : adj[at]) {
            auto& e = edges[i];
            if(h[e.to]>=h[at]) {
                h[at]+=1;
                renew = true;
            }
        }
        if(renew) {
            q.push(at);
        }
    }
    ll solve() {
        h[0] = n;
        q.push(0);
        excess[0] = 1e18;
        while(!q.empty()) {
            int at = q.front();
            q.pop();
            push(at);

        }
        return excess[n-1];
    }
};
int main() {
    int n; cin >> n;
    vi a(n),b(n);
    for(int& i: a) cin >> i;
    for(int& i: b) cin >> i;
    // Check for every last element
    flow f(n+2);
    ll ans = 0;
    for(int i=0;i<n;++i) {
        if(b[i]>0) {
            ans+=b[i];
            f.addEdge(0,i+1,b[i]);
        } else if(b[i]<0) {
            f.addEdge(i+1,n+1, -b[i]);
        }
        bitset<101> used;
        for(int j=i-1;j>=0;--j) {
            if(!used[a[j]] and a[i]%a[j]==0) {
                used[a[j]] = true;
                f.addEdge(i+1,j+1,oo);
            }
        }
    }
    cout << ans-f.solve() << endl;

}