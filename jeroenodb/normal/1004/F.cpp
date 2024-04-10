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
const int mxN = 1e5+1, oo = 1e9, LG=20;
int x;
// Complexity: O((n + q log(n))*log(A)*log(log(A))
struct segtree {
    int ptwo;
    struct node {
        int pre[LG], suf[LG],len=1;
        ll good=0;
        node() {}
        node(int a) {
            for(int i=0;i<LG;++i) {
                pre[i]=suf[i]=!(a&(1<<i));
                suf[i]=-suf[i];
            }
            if(a>=x) good=1;
        }
    };
    vector<node> seg;
    segtree(){}
    node& operator[](int i) {
        return seg[i+ptwo];
    }
    node merge(node& l, node& r) {
        if(l.len==0) return r;
        if(r.len==0) return l;
        node res;
        res.len=l.len+r.len;
        for(int i=0;i<LG;++i) {
            if(l.pre[i]!=l.len) res.pre[i]=l.pre[i];
            else res.pre[i]=l.len+r.pre[i];
            if(r.suf[i]!=-1) res.suf[i]=l.len+r.suf[i];
            else res.suf[i]=l.suf[i];
        }
        res.good = l.good+r.good;
        // update good with  segments crossing mid, using l.suf and r.pref
        int lo[LG],ro[LG];
        iota(lo,lo+LG,0), iota(ro,ro+LG,0);
        sort(lo,lo+LG,[&](int a, int b){return l.suf[a]>l.suf[b];});
        sort(ro,ro+LG,[&](int a, int b){return r.pre[a]<r.pre[b];});
        int lor[LG], ror[LG]; // prefix OR
        lor[0]=ror[0]=0;
        for(int i=0;i<LG;++i) {
            if(i) lor[i]=lor[i-1], ror[i]=ror[i-1];
            if(l.suf[lo[i]]!=-1) lor[i]|=1<<lo[i];
            if(r.pre[ro[i]]!=r.len) ror[i]|=1<<ro[i];
        }
        // two pointers
        for(int i=-1,j=LG-1;i<LG;++i) {
            if(i>=0) {
                while(j and (ror[j-1]|lor[i])>=x) j--;
                if(j==0 and lor[i]>=x) {
                    int leftlen = l.suf[lo[i]];
                    if(i!=LG-1) leftlen-=l.suf[lo[i+1]];
                    else leftlen++;
                    res.good+=(ll)leftlen*r.len;
                } else if((lor[i]|ror[j])>=x) {
                    // add something to good
                    // from (l.suf[lo[i+1]], l.suf[lo[i]] ] to [ r.pre[ro[j]]], r.len]
                    int leftlen = l.suf[lo[i]];
                    if(i!=LG-1) leftlen-=l.suf[lo[i+1]];
                    else leftlen++;
                    int rightlen = r.len-r.pre[ro[j]];
                    res.good+=(ll)leftlen*rightlen;
                }
            } else if(ror[j]>=x) {
                while(j and ror[j-1]>=x) j--;
                int leftlen = l.len-l.suf[lo[0]]-1;
                int rightlen = r.len-r.pre[ro[j]];
                res.good+=(ll)leftlen*rightlen;
            }
        }
        return res;

    }
    segtree(int nn) {
        ptwo=1;
        while(ptwo<nn) 
            ptwo*=2;
        seg.resize(ptwo*2);
        for(int i=nn;i<ptwo;++i) {
            seg[i+ptwo].len=0;
        }
    }
    void update(int i, int val) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        seg[i] = node(val);
        for(i/=2;i>=1;i/=2) {
            seg[i] = merge(seg[2*i],seg[2*i+1]);
        }
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        node le, ri;
        le.len=ri.len=0;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q >> x;
    segtree seg(n);
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        seg[i] = segtree::node(a);
    }
    seg.build();
    while(q--) {
        int t; cin >> t;
        if(t==1) {
            int i,y; cin >> i >> y,--i;
            seg.update(i,y);
        } else {
            int l,r; cin >> l >> r,--l,--r;
            cout << seg.query(l,r).good << '\n';
        }
    }
}