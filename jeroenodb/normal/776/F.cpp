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
const int mxN = 1.5e5+1, oo = 1e9;
vi adj[mxN];
string ans;
bool visited[mxN];
int sz[mxN];
void dfsz(int at, int from) {
    sz[at] = 1;
    for(int to:adj[at]) {
        if(!visited[to] and to !=from) {
            dfsz(to,at);
            sz[at]+=sz[to];
        }
    }

}
int centroid(int at) {
    int total = sz[at], from = -1;
    bool done = false;
    while(!done) {
        done = true;
        for(int to: adj[at]) if(from!=to and !visited[to]) {
            if(sz[to]*2>total) {
                done = false;
                from = at;
                at = to;
                break;
            }
        }
    }
    return at;
}
void decomp(int at=0,char rank=1) {
    dfsz(at,-1);
    int c = centroid(at);
    visited[c] = true;
    ans[c]=rank;
    for(int to: adj[c]) {
        if(!visited[to]) decomp(to,rank+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // array linked list
    // generate tree, do the things
    
    int n,m; cin >> n >> m;
    vvi regions; regions.reserve(n);
    vi l(n),r(n); int head=0; // head of linked list
    vector<bool> removed(n);
    iota(all(l),-1); l[0]=n-1;
    iota(all(r),1); r[n-1]=0; // circular linked list
    vector<array<int,3>> diags;
    diags.reserve(2*m);
    for(int i=0;i<m;++i) {
        int a,b; cin >> a >> b,--a,--b;
        diags.push_back({(b-a+2*n)%n,a,b});
        diags.push_back({(a-b+2*n)%n,b,a});
    }
    sort(all(diags));
    // now do onion peeling
    auto addedge = [&](int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    };
    vi regionid(n,-1);
    ll iters=0;
    auto makeregion = [&](int a, int b, bool atlast = true) {
        int at = a;
        vi pts;
        do {
            if(at!=a and at!=b) removed[at]=true;
            pts.push_back(at);
            if(regionid[at]!=-1) {
                addedge(regions.size(),regionid[at]);
            }
            at = r[at];
        } while(at!=b);
        if(atlast) pts.push_back(at);
        sort(pts.rbegin(),pts.rend());
        regions.push_back(pts);
    };

    for( auto [len,a,b] : diags) {
        if(l[a]==b) continue; // nowhere left to split
        if(removed[a] or removed[b]) continue;
        makeregion(a,b);
        r[a] = b; // remove piece
        l[b] = a;
        regionid[a] = regions.size()-1;
        head = a;
    }
    makeregion(head,head,false);
    n = regions.size();
    ans.resize(n);

    decomp();
    vi ord(n); iota(all(ord),0);
    sort(all(ord) , [&](int i, int j) {return regions[i]<regions[j];});
    for(auto i : ord) {
        cout << int(ans[i]) << ' ';
    }
    
}