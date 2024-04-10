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
void nope() {
    cout << "-1\n";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // berland army
    // Topo sort
    // But then maybe impossible to have r_1 >= r_2, with them in the order?
    // give the highest order to someone without orders!
    // What if that order already exists?
    // From man with lowest rank, BFS upwards?
    // You have constraints: r_i+1 <= r_j
    // can be done with an edge from i to j of weight 1 and running shortest path
    // Constraint that all ranks have to be covered is hard!
    // Can give constraints on each node.
    // Greedily, when you have constraints: 
    // Pick someone with indegree 0, and highest lowerbound, and put him as the next highest rank
    // With priority queue
    int n,m,k; cin >> n >> m >> k;
    vi lo(n); for(auto& i : lo) cin >> i;
    vi hi = lo; for(auto& i : hi) if(i==0) i = k;
    for(auto& i : lo) i+=(i==0);
    vvi adj(n);
    vi deg(n);
    while(m--) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        deg[v]++;
    }
    
    {
        vi q, deg2=deg;
        for(int i=0;i<n;++i) if(deg2[i]==0) q.push_back(i);
        for(int i=0;i<(int)q.size();++i) {
            auto at = q[i];
            for(auto to : adj[at]) 
                if(--deg2[to]==0) 
                    q.push_back(to);
        }
        if((int)q.size()!=n) // not a DAG!
            nope();
        reverse(all(q));
        for(auto i : q) {
            for(auto to : adj[i]) 
                lo[i]=max(lo[i],lo[to]+1);
        }
    } // calculated lower bounds of ranks of each man.
    priority_queue<pi> pq,pq2;
    for(int i=0;i<n;++i) if(deg[i]==0) {
        pq2.push({hi[i],i});
    }
    int need=k;
    while(!pq.empty() or !pq2.empty()) {
        while(!pq2.empty() and pq2.top().first>=need) {
            auto [h,at] = pq2.top(); pq2.pop();
            pq.push({lo[at],at});
        }
        if(!pq.empty()) {
            // greedily pick man with highest lowerbound
            auto [l,at] = pq.top(); pq.pop();
            if(lo[at]>hi[at]) nope();
            // impossible to give 'at' a rank
            if(l<=need) // found candidate for next rank I need
                hi[at]=need--; 
            // else just give this candidate the highest rank
            for(auto to : adj[at]) {
                hi[to] = min(hi[to],hi[at]-1);
                // update upperbounds on the fly
                if(--deg[to] == 0) {
                    // standard toposort
                    pq2.push({hi[to],to});
                }
            }
        } else nope(); // didn't find any man for for rank = need
    }
    if(need!=0) nope(); // didn't finish with all ranks
    cout << hi << '\n';
}