#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
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
int ans = 0;
int delta=0;

using namespace __gnu_pbds;

struct DSU{
    vector<int> sz,parent;
    int components;
    multiset<int> s1,s2;
    int sm = 1,delta=1;
    void fix() {
        if(!s1.empty() and !s2.empty() and *prev(s1.end()) > *s2.begin()) {
            auto it2 = s2.begin(), it = prev(s1.end());
            auto a = *it, b = *it2;
            s1.erase(it), s2.erase(it2);
            sm+=a-b;
            s2.insert(a);
            s1.insert(b);
        }
        while(s2.size()<delta and !s1.empty()) {
            auto it2 = prev(s1.end());
            sm+=*it2;
            s2.insert(*it2);
            s1.erase(it2);
            
        }
    }
    void erase(int s) {
        auto it = s1.find(s);
        if(it!=s1.end()) s1.erase(it);
        else {
            s2.erase(s2.find(s));
            sm-=s;
        }
        fix();
    }
    void insert(int s) {
        s1.insert(s);
        fix();
    }
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        iota(all(parent),0);
        for(int i=0;i<n-1;++i) s1.insert(1);
        s2.insert(1);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        insert(sz[a]+sz[b]);
        erase(sz[a]);
        erase(sz[b]);
        sz[a]+=sz[b];
        
        parent[b] = a;
    }
    void unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        else delta++;
        fix();
    }
    int find(int a) {
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d; cin >> n >> d;
    DSU dsu(n);
    for(int i=0;i<d;++i) {
        int x,y; cin >> x >> y,--x,--y;
        dsu.unite(x,y);
        cout << dsu.sm-1 << '\n';
    }
}