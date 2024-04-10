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
    int a=0,b=0,c=0,ab=0,bc=0,abc=0;
    node() {
        *this = node(0);
    }
    node(char ch) {
        a = ch=='a',b = ch=='b', c = ch=='c';
    }
    void merge(const node& o) {
        abc = min({abc+o.c, a+o.abc, ab+o.bc});
        ab = min(ab+o.b, a+o.ab);
        bc = min(bc+o.c, b+o.bc);
        a+=o.a,b+=o.b,c+=o.c;
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
        ptwo=1; while(ptwo<nn) ptwo*=2;
        seg.assign(ptwo*2,0);
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        node resl, resr;
        while(l and l<=r) {
            if(l%2==1) resl = merge(resl,seg[l++]);
            if(r%2==0) resr = merge(seg[r--],resr);
            l/=2; r/=2;
        }
        return merge(resl,resr);
    }
    void update(int i, char val) {
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
    segtree seg(n);
    for(int i=0;i<n;++i) {
        char c; cin >> c;
        seg[i]=c;
    }
    seg.build();
    while(q--) {
        int i; char c; cin >> i >> c,--i;
        seg.update(i,c);
        cout << seg.seg[1].abc << '\n';
    }
}