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
const int store=2e6 + 2;
bitset<store> sieve={};
int factor[store] = {};
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
struct DSU{
    vector<int> sz,parent;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        parent[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int find(int a) {
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};
set<int> getF(int a) {
    set<int> res;
    while(a!=1) {
        int f = factor[a];
        while(a%f==0) a/=f;
        res.insert(f);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makesieve();
    int n,q; cin >> n >> q;
    DSU dsu(int(2e6)+2); // dsu of prime factors
    vi a(n); 
    for(auto& i : a) {
        cin >> i;
        auto fs = getF(i);
        int last=*fs.begin();
        for(auto f : fs) {
            dsu.unite(last,f);
        }
    }
    set<pi> edges;
    for(auto i : a) {
        auto fs = getF(i);
        auto fs2 = getF(i+1);
        fs.merge(fs2);
        for(auto o : fs) for(auto j : fs) {
            o = dsu.find(o),j = dsu.find(j); // get labels of CC's of o and j
            edges.insert({o,j});
        }
    }
    while(q--) {
        int s,t; cin >> s >> t,--s,--t;
        s = dsu.find(factor[a[s]]); // get labels of CC's of a_s and a_t
        t = dsu.find(factor[a[t]]);
        if(s==t) {
            cout << "0\n";
        } else if(edges.count({s,t}) or edges.count({t,s})) cout << "1\n";
        else cout << "2\n";
    }




}