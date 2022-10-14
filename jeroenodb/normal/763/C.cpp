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
    mdint (long long _d) : d(_d%MOD) {
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
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n; cin >> m >> n;
    MOD=m;
    vi a(n); for(auto& i : a) cin >> i;

    bool flip=false;
    if(n==m or n==1) {
        cout << a[0] << " 1" << '\n';
        exit(0);
    }
    if(n*2>m) {
        vi b;
        sort(all(a));
        a.push_back(m);
        int j=0;
        for(int i: a) {
            while(j<i) b.push_back(j++);
            j++;
        }
        a=b;
        flip=true;
    }
    n = a.size();
    if(n==1) {
        assert(flip);
        cout << mint(a[0]+1) << " 1" << '\n';
        exit(0);
    }
    mint sm=0;
    for(int i : a) sm+=i;
    assert(n<m);
    shuffle(all(a),rng);
    ll arithsum = (ll)n*(n-1)/2;
    set<int> s(all(a));
    for(int i=1;i<n;++i) {
        mint d = a[i]-a[0];
        mint x = (sm-d*arithsum)/n;
        mint ori = x;
        if(s.count(x.d)) {
            bool good=true;
            for(int j=1;j<n;++j) {
                x+=d;
                if(!s.count(x.d)) {
                    good=false;
                    break;
                }
            }
            if(good) {
                if(flip) ori=x+d;
                cout << ori << ' ' << d << '\n';
                exit(0);
            }
        }
    }
    cout << "-1\n";

}