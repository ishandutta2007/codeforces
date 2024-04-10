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
long long MOD = 1e9+7;
struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){
        if(d<0) d+=MOD;
    };
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
    bool operator==(const mdint& o) const { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint;
vector<mint> F;
const int H = 4;

struct S {
    int n;
    vector<mint> a;
    ll total=0;
    void update(int i, mint v) {
        total-=a[i].d;
        a[i]=v;
        total+=a[i].d;
    }
    S(int nn) : n(nn),a(nn+1) {
        for(int i=1;i<=n;++i) cin >> a[i];
        for(int i=1;i<=n;++i) {
            int b; cin >> b;
            a[i]-=b;
        }
        for(int i=n;i>1;--i) {
            a[i]-=a[i-1]+a[i-2];
        }
        for(int i=0;i<=n;++i) total+=a[i].d;
    }

    void update(int l, int r, int sgn) {
        update(l,a[l]+sgn);
        if(r<=n) 
            update(r,a[r]-F[r-l]*sgn);
        if(r+1<=n) 
            update(r+1, a[r+1]-(F[r-l+1]-F[r-l])*sgn);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q >> MOD;
    F.resize(n+3);
    F[0]=F[1]=1;
    for(int i=2;i<n+3;++i) F[i]=F[i-1]+F[i-2];
    S AsubB(n);
    while(q--) {
        char c; int l, r;
        cin >> c >> l >> r;
        AsubB.update(l,r+1,c=='A'?1:-1);
        cout << (AsubB.total==0?"YES\n":"NO\n");
    }
    


    
}