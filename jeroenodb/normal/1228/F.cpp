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
// find centroid
int sz[mxN],n;
vi adj[mxN];
void dfsz(int at, int from=-1) {
    sz[at]=1;
    for(int to : adj[at]) if(to!=from) {
        dfsz(to,at);
        sz[at]+=sz[to];
    }
}
int centroid(int at) {
    bool done=false;
    int from=at;
    while(!done) {
        done=true;
        for(int to : adj[at]) if(to!=from) {
            if(sz[to]>n/2) {
                from=at;
                at = to;
                done=false;
                break;
            }
        }
    }
    return at;
}
vi bad;
void impos() {
    cout << "0\n";
    exit(0);
}
int verify(int at) {
    map<int,int> ds;
    if(adj[at].size()==0) return 0;
    if(adj[at].size()>3) {
        return -oo;
    }
    for(int to : adj[at]) {
        adj[to].erase(find(all(adj[to]),at));
        int d = verify(to);
        ds[d]++;
        adj[to].push_back(at);
        if(d==-oo) return -oo;
    }
    if(adj[at].size()==1) {
        // must be last level
        if(ds.begin()->first!=0) return -oo;
        bad.push_back(at);
        return 1;
    }
    if(adj[at].size()==2 and ds.size()!=1) return -oo;
    if(adj[at].size()==3 and ds.begin()->second!=2) return -oo;
    if(adj[at].size()==3) bad.push_back(at);
    return ds.rbegin()->first+1;
}
vi res;
void check(int at) {
    bad.clear();
    if(verify(at)==-oo) 
        return;
    if(bad.size()==1) res.push_back(bad.back());
}
int main() {
    int lg; cin >> lg;
    n = (1<<lg) - 2;
    if(n==2) {
        cout << "2\n1 2\n";
        exit(0);
    }
    for(int i=0;i<n-1;++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsz(1);
    int c = centroid(1);
    vi v = {c};
    if(adj[c].size()>5) impos();
    for(auto to : adj[c]) 
        v.push_back(to);
    // centroid must be root
    for(auto i : v) check(i);
    sort(all(res));
    cout << res.size() << "\n" << res << '\n';



}