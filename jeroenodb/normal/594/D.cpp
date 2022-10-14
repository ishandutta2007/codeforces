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
const long long MOD = 1e9+7;
const int store=1e6 + 1;
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
    int ptwo;
    vector<mint> seg;
    segtree(){}
    mint& operator[](int i) {
        return seg[i+ptwo];
    }
    segtree(int nn) {
        ptwo=1;
        while(ptwo<nn) 
            ptwo*=2;
        seg.assign(ptwo*2,1);
    }
    auto query(int l, int r) {
        assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
        l+=ptwo; r+=ptwo;
        mint res = 1;
        while(l and l<=r) {
            if(l%2==1) res = res*seg[l++];
            if(r%2==0) res = res*seg[r--];
            l/=2; r/=2;
        }
        return res;
    }
    void update(int i, int val, bool special=false) {
        assert(i>=0 and i<ptwo);
        i+=ptwo;
        if(special) seg[i] = (seg[i].d/(val-1))*val;
        else seg[i]=val;
        for(i/=2;i>=1;i/=2) {
            seg[i] = seg[2*i]*seg[2*i+1];
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makesieve();
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    int q; cin >> q;
    vi qf(n,-1),nxt(q,-1),qs(q);
    for(int i=0;i<q;++i) {
        auto& l = qs[i];
        int r; cin >> l >> r;
        --l,--r;
        nxt[i]=qf[r],qf[r]=i;
    }
    unordered_map<int,int> primes;
    segtree seg(n);
    vector<mint> ans(q);
    for(int i=0;i<n;++i) {
        int myq=a[i];
        while(a[i]!=1) {
            auto& f = factor[a[i]];
            while(factor[a[i]]==f) a[i]/=f;
            if(primes.count(f)) {
                seg.update(primes[f],f,true);
            }
            myq-=myq/f;
            primes[f]=i;
        }
        seg.update(i,myq);
        for(int j=qf[i];j!=-1;j=nxt[j]) {
            ans[j]=seg.query(qs[j],i);
        }
    }
    for(auto i : ans) {
        cout << i.d << '\n';
    }

}