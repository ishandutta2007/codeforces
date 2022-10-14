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
struct node {
    int sm=0,ans=-1, mx=0,mn=0,tw[2] = {};
    node() {}
    node(int val) {
        sm=val;
        ans=0;
    }
    void merge(node o) {
        if(ans==-1) return void(*this=o);
        else if(o.ans==-1) return;
        // add sm to everything in o?
        o.mx+=sm, o.mn+=sm, o.tw[0]-=sm,o.tw[1]-=sm;
        ans = max({ans,o.ans, tw[0]+o.mx, mx+o.tw[1]});
        tw[0] = max({tw[0],o.tw[0],mx-2*o.mn});
        tw[1] = max({tw[1],o.tw[1],o.mx-2*mn});
        mx=max(mx,o.mx);
        mn=min(mn,o.mn);
        sm+=o.sm;
    }
    friend node merge(node a, const node& b) {
        a.merge(b);
        return a;
    }
};
struct segtree {
    int ptwo;
    vector<node> seg;
    segtree(){}
    node& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=1;
        while(ptwo<nn) ptwo*=2;
        seg.resize(ptwo*2);
    }
    void update(int i, int val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = node(val);
        for(i/=2;i>=1;i/=2) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    segtree seg(2*(n-1));
    for(int i=0;i<2*(n - 1);++i) {
        char c; cin >> c;
        if(c=='(') seg[i]=node(1);
        else seg[i] = node(-1);
    }
    seg.build();
    cout << seg.seg[1].ans << '\n';
    while(q--) {
        int a,b; cin >> a >> b;
        --a,--b;
        int c = seg[a].sm, d = seg[b].sm;
        seg.update(a,d),seg.update(b,c);
        cout << seg.seg[1].ans << '\n';
    }
}