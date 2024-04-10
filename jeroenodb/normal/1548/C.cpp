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
const long long MD = 1e9+7;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){};
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = mdint((ll)a.d*o.d);
    }
    mdint operator*(const mdint& o) const {
        mdint res = *this;
        res*=o;
        return res;
    }
    mdint operator+(const mdint& o) const {
        mdint res = *this;
        res+=o;
        return res;
    }
    mdint operator-(const mdint& o) const {
        mdint res = *this;
        res-=o;
        return res;
    }
    mdint operator^(long long b) const {
        mdint tmp = 1;
        mdint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    friend mdint operator/=(mdint& a, const mdint& o) {
        a *= (o^(MOD-2));
        return a;
    }
    mdint operator/(const mdint& o) {
        mdint res = *this;
        res/=o;
        return res;
    }
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<MD>;
const int mxF = 3.5e6+2;
mint fact[mxF], ifact[mxF];
mint ncr(int a, int b) {
    if(b>a or a<0) return 0;
    return fact[a]*ifact[b]*ifact[a-b];
}
void precomp() {
    fact[0]=1;
    for(int i=1;i<mxF;++i) {
        fact[i]=fact[i-1]*i;
    }
    ifact[mxF-1] = mint(1)/fact[mxF-1];
    for(int i=mxF-2;i>=0;--i) {
        ifact[i]=ifact[i+1]*(i+1);
    }
}
typedef vector<mint> vm;
vm binom(int n) {
    vm res(n+1);
    for(int i=0;i<=n;++i) {
        res[i] = ncr(n,i);
    }
    return res;
}
template<typename T> T operator+(T a, const vm& b) {
    a.resize(max(a.size(),b.size()));
    for(int i=0;i<b.size();++i) a[i]+=b[i];
    return a;
}
template<typename T> T operator-(T a, const vm& b) {
    a.resize(max(a.size(),b.size()));
    for(int i=0;i<b.size();++i) a[i]-=b[i];
    return a;
}
vm operator*(mint a, vm b) {
    for(auto& i : b) i*=a;
    return b;
}
template<typename T, int C> struct mydeque {
    T ar[C];
    int head=0, tail=-1;
    T& operator[](int i) {return ar[(head+i)%C];}
    void pop_back() {
        tail--;
        if(tail<0) tail=C-1;
    }
    T& back() {return ar[tail];}
    void push_front(T a) {
        if(--head<0) head=C-1;
        ar[head]=a;
    }
    void push_back(T a) {
        if(++tail>=C) tail=0;
        ar[tail]=a;
    }
    size_t size() {
        int dif = tail-head+1;
        if(dif<0) dif+=C;
        return dif;
    }
    void resize(int n) {
        while(size()<n) push_back(0);
    }
};
vm operator/(vm a, vm b) {
    vm c; c.reserve(a.size()-b.size()+1);
    mydeque<mint,16> rem; rem.push_back(0);
    mint inv = mint(1)/b.back();
    b.back()=0;
    for(int i=a.size()-1;i>=b.size()-1;--i) {
        c.push_back((a[i]-rem.back())*inv);
        rem = rem + c.back()*b;
        rem.pop_back();
        rem.push_front(0);
    }
    reverse(all(c));
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    int n,q; cin >> n >> q;
    vm ans = (binom(3*n+3)-binom(3))/(binom(3)-vm{1});
    while(q--) {
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
}