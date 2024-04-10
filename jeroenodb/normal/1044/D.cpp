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
struct DSU{
    struct node {
        int par=-1,delta=0;
    };
    map<int,node> ar;
    void link(int a, int b, int xr) {
        if(ar[a].par>ar[b].par) {
            swap(a,b);
        }
        auto &na = ar[a], &nb = ar[b];
        na.par += nb.par;
        nb.delta = xr;
        nb.par = a;
    }
    bool unite(int a, int b, int xr) {
        auto pa = find(a);
        auto pb = find(b);
        if(pa!=pb) 
            link(pa,pb, xr^ar[a].delta^ar[b].delta);
        else if(xr!= (ar[a].delta^ar[b].delta)) 
            return false;
        return true;
    }
    int query(int a, int b) {
        if(!ar.count(a) or !ar.count(b)) return -1;
        auto pa = find(a);
        auto pb = find(b);
        if(pa==pb) return ar[a].delta^ar[b].delta;
        return -1;
    }
    int find(int a) {
        auto& na = ar[a];
        if(na.par<0) return a;
        int res =  find(na.par);
        na.delta ^= ar[na.par].delta;
        na.par=res;
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    DSU dsu;
    int last=0;
    while(q--) {
        int t; cin >> t;
        int l,r; cin >> l >> r;
        l^=last,r^=last;
        if(l>r) swap(l,r);
        ++r;
        if(t==1) {
            int x; cin >> x;
            x^=last;
            dsu.unite(l,r,x);
        } else {
            last = dsu.query(l,r);
            cout << last << '\n';
            last = abs(last);
        }
    }
}