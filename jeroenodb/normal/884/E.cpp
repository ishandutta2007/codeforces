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
const int mxM  = 1<<14;
struct DSU{
    short sz[mxM];
    int components;
    DSU(int n) {
        fill(sz,sz+n,-1);
        components = n;
    }
    void link(int a, int b) {
        components--;
        if(sz[a]>sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        sz[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int find(int a) {
        if(sz[a]<0) return a;
        return sz[a] = find(sz[a]);
    }
};

bitset<mxM> bs;
short prv[mxM],last[mxM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    DSU dsu(m);
    fill(prv,prv+m,-1);
    int ans=0;
    for(int i=0;i<n;++i) {
        dsu = DSU(m);
        // reading in input
        for(int j=0;j<m/4;++j) {
            char c; cin >> c;
            if(c<='9') 
                c-='0';
            else 
                c-='A'-10;
            for(int k=0;k<4;++k) {
                bs[j*4+k] = c>>(3-k) & 1;
            }
        }
        fill(last,last+m,-1);
        // debug(bs);
        // connecting edges
        for(int j=0;j<m;++j) {
            if(prv[j]!=-1 and bs[j]) {
                auto u = prv[j];
                if(last[u]!=-1) dsu.unite(last[u],j);
                last[u]=j;
            }
            if(j and bs[j] and bs[j-1]) 
                dsu.unite(j,j-1);
        }
        for(int j=0;j<m;++j) if(prv[j]!=-1) {
            if(last[prv[j]]==-1) {
                ans++;
                last[prv[j]]=0;
            }
        }
        // preparing for next
        for(int j=0;j<m;++j) {
            if(bs[j]) prv[j] = dsu.find(j);
            else prv[j]=-1;
        }
    }
    cout << ans + bs.count() - (m-dsu.components);
}