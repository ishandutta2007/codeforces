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
typedef complex<int> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n,m;
pair<bool,bool> inside(pt p) {
    return {1<=p.X and p.X<=n, 1<=p.Y and p.Y<=m};
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int dist(pt at) {
    return min(abs(at.X),abs(at.Y));
}
void solve() {
    cin >> n >> m;
    pt s,dirt; read(s),read(dirt);
    vector<bool> canhit;
    auto at = s;
    pt v = {1,1};
    auto fixv = [&]() {
        auto to = at+v;
        auto [xo, yo] = inside(to);
        if(!xo) v = {-v.X,v.Y};
        if(!yo) v = {v.X,-v.Y};
    };
    fixv();
    auto startv = v;
    do {
        
        canhit.push_back(dist(at-dirt)==0);
        at +=v;
        fixv();
    } while( !(at==s and v== startv));
    mint prob=1;
    mint p; cin >> p;
    p/=100;
    auto q = mint(1)-p;
    mint res=0;
    for(int i=0;i<canhit.size();++i) {
        if(canhit[i]) {
            res+=prob*p*i;
            prob*=q;
        }
    }
    res+=prob*canhit.size();
    res/=mint(1)-prob;
    cout << res << '\n';

}
int main() {
    int t; cin >> t;
    while(t--) solve();
}