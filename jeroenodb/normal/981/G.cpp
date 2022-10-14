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
const int mxN = 2e5+10, oo = 1e9;
const long long MOD = 998244353;
class mint {
public:
    int d;
    mint () {d=0;}
    mint (long long _d) : d(_d%MOD){};
    mint operator*(const mint& o) const {
        return ((ll)d*o.d)%MOD;
    }
    mint operator+(const mint& o) const {
        long long tmp = d+o.d;
        if(tmp>=MOD) tmp-=MOD;
        return tmp;
    }
    mint operator-(const mint& o) const {
        long long tmp = d-o.d;
        if(tmp<0) tmp+=MOD;
        return tmp;
    }
    mint operator^(long long b) const {
        mint tmp = 1;
        mint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    mint operator/(const mint& o) {
        return *this * (o^(MOD-2));
    }
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
struct segtree {
    struct node {
        mint sm=0, lazy[2] = {1,0};
        node() {}
    };
    vector<node> seg;
    int n,ptwo;
    segtree() {}
    segtree(int nn) {
        n=nn,ptwo=1;
        while(ptwo<n) ptwo*=2;
        seg.resize(2*ptwo);
    }
    void updateNode(int i, bool type, mint times, int len) {
        // apply a*sm first, then + b
        auto& v = seg[i];
        if(!type) {
            v.sm=v.sm*times;
            v.lazy[1]=v.lazy[1]*times;
            v.lazy[0]=v.lazy[0]*times;
        } else {
            v.sm+=times*len;
            v.lazy[1]+=times;
        }
    }
    void push(int i, int len) {
        for(int k : {0,1}) {
            if(seg[i].lazy[k].d) {
                updateNode(i*2,k,seg[i].lazy[k],len/2);
                updateNode(i*2+1,k,seg[i].lazy[k],len/2);
            }
            seg[i].lazy[k]=!k;
        }
    }
    void pull(int i) {
        auto& v = seg[i];
        v.sm=seg[i*2].sm+seg[i*2+1].sm;
    }
    mint get(int i, int l, int r, int ql, int qr) {
        if(qr<l or r<ql) return 0;
        if(ql<=l and r<=qr) return seg[i].sm;
        push(i,r-l+1);
        int mid = (l+r)/2;
        auto sum = get(i*2,l,mid,ql,qr)+get(i*2+1,mid+1,r,ql,qr);
        pull(i);
        return sum;
    }

    void set(int i, int l, int r, int ql, int qr, bool type) {
        if(qr<l or r<ql) return;
        if(ql<=l and r<=qr) {
            updateNode(i,type,!type + 1,r-l+1);
            return;
        }
        push(i,r-l+1);
        int mid = (l+r)/2;
        set(i*2,l,mid,ql,qr,type),set(i*2+1,mid+1,r,ql,qr,type);
        pull(i);
    }
    void Set(int a, int b, bool type) {
        set(1,0,ptwo-1,a,b,type);
    }
    node& operator[](int i) {return seg[i+ptwo];}
    void build() {
        for(int i=ptwo-1;i>=1;--i) {
            pull(i);
        }
    }
};
map<int,int> color[mxN];
auto cut(map<int,int>& m, int i) {
    // cut between i-1 and i
    auto it = m.lower_bound(i);
    if(it!=m.end() and it->second<i) {
        m[i-1]=it->second;
        it->second=i;
    }
}
segtree seg;
void update(int i, int j, int x) {
    auto& s = color[x];
    cut(s,i), cut(s,j+1);
    int ori = i;
    for(auto it = s.lower_bound(i);it!=s.end() and it->first<=j;it = s.erase(it)) {
        if(i!=it->second) seg.Set(i,it->second-1,true);
        seg.Set(it->second, it->first,false);
        i=it->first+1;
    }
    if(i<=j) seg.Set(i,j,true);
    s[j]=ori;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    seg = segtree(n);

    for(int i=0;i<q;++i) {
        int t,l,r; cin >> t >> l >> r,--l,--r;
        if(t==1) {
            int x; cin >> x;
            update(l,r,x);
        } else {
            cout << seg.get(1,0,seg.ptwo-1,l,r).d << '\n';
        }
    }
}