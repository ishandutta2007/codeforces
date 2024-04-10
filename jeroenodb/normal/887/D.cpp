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
struct segtree {
    int ptwo;
    struct node {
        ll sm=0,prefmin=0;
        node() {}
        node(int a) {sm=prefmin=a;}
    };
    vector<node> seg;
    segtree(){}
    node& operator[](int i) {
        return seg[i+ptwo];
    }
    node merge(node& l, node& r) {
        node res;
        res.sm=l.sm+r.sm;
        res.prefmin = min(l.prefmin,l.sm+r.prefmin);
        return res;
    }
    segtree(int nn) {
        ptwo=1;
        while(ptwo<nn) 
            ptwo*=2;
        seg.resize(ptwo*2);
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        node le, ri;
        while(l and l<=r) {
            if(l%2==1) le = merge(le,seg[l++]);
            if(r%2==0) ri = merge(seg[r--],ri);
            l/=2; r/=2;
        }
        return merge(le,ri);
    }
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            seg[i]=merge(seg[i*2],seg[i*2+1]);
        }
    }
};
int main() {
    int n,a,b,c,d,start,len; cin >> n >> a >> b >> c >> d >> start >> len;
    segtree seg(n);
    vi t(n),q(n);
    for(int i=0;i<n;++i) {
        cin >> t[i] >> q[i];
        if(q[i]==0) seg[i]=-d;
        else seg[i]=c;
    }
    seg.build();
    ll pref=start, worst=start;
    // check t=0
    {
        int j=-1;
        while(j<n-1 and t[j+1]<len) ++j;
        if(j==-1 or start+seg.query(0,j).prefmin>=0) {
            cout << "0\n";
            exit(0);
        }
    }
    for(int i=0,j=0;i<n;++i) {
        while(j<n-1 and t[j+1]<=t[i]+len) {
            ++j;
        }
        if(q[i]==0) pref-=b;
        else pref+=a;
        worst = min(worst,pref);
        if(worst<0) break;
        if(i+1>j) {
            cout << t[i]+1 << '\n';
            exit(0);
        }
        // try [t_i+1, t_i+len]
        auto good = min(worst,pref+seg.query(i+1,j).prefmin);
        if(good>=0) {
            cout << t[i]+1 << '\n';
            exit(0);
        }
    }
    if(worst>=0) {
        cout << t.back()+1 << '\n';
    } else cout << "-1\n";
}