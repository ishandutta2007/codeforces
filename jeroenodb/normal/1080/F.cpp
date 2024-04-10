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
const int mxN = 8e6+1, oo = 1e9+3;
struct node;
node *seg;
int pp=1;
// persistent seg tree
struct node {
    int mx=oo;
    int c[2]={};
    int child(int i) {
        if(c[i]) return c[i];
        c[i] = pp++;
        seg[c[i]] = node();
        return c[i];
    }
    void recalc() {
        mx=max(seg[c[1]].mx,seg[c[0]].mx);
    }
    int update(int i, int v, int l, int r) {
        int mp = pp++;
        if(l==r-1) {
            seg[mp] = node{min(v,mx)};
            return mp;
        }
        node& nw = seg[mp];
        nw = *this;
        int mid = (l+r)/2;
        if(i<mid) nw.c[0] = seg[nw.c[0]].update(i,v,l,mid);
        else nw.c[1] = seg[nw.c[1]].update(i,v,mid,r);
        nw.recalc();
        return mp;
    }
    int query(int a, int b, int l, int r) {
        if(b<=l or r<=a) return -oo;
        if(a<=l and r<=b) {
            return mx;
        }
        int mid = (l+r)/2;
        return max(seg[c[0]].query(a,b,l,mid),seg[c[1]].query(a,b,mid,r));
    }
};
int build(int l, int r) {
    int c = pp++;
    seg[c] = node();
    if(l==r-1) return c;
    int mid = (l+r)/2;
    seg[c].c[0] = build(l,mid);
    seg[c].c[1] = build(mid,r);
    return c;
}
typedef array<int,3> iv;
int main() {
    seg = new node[mxN];
    int n,m,k; cin >> n >> m >> k;
    vector<iv> ivs(k);
    for(auto& [l,r,p]: ivs) {
        cin >> l >> r >> p;
    }
    vi roots(k+1);
    sort(all(ivs));
    roots[k] = build(1,n+1);
    for(int i=k-1;i>=0;--i) {
        auto [l,r,p] = ivs[i];
        roots[i] = seg[roots[i+1]].update(p,r,1,n+1);
    }
    while(m--) {
        int a,b,x,y; cin >> a >> b >> x >> y;
        int j = lower_bound(all(ivs),iv{x,-1,-1})-ivs.begin();
        int W = seg[roots[j]].query(a,b+1,1,n+1);
        if(W<=y) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}