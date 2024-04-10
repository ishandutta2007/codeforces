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
const int mxN = 3000+1, oo = 1e9;
const long long MD = 1e9+7;
template<long long MOD=MD> struct mdint {
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
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<MD>;
mint dp[2][mxN][mxN];
string ss;
int m,d;
int pw[mxN];
bool isA=false;
mint solve(bool bg,int i, int j) {
    if(i==-1) return j==0 and (!isA or !bg);
    auto& c = dp[bg][i][j];
    if(c.d!=-1) return c;
    c=0;
    int lim = bg?(ss[i]-'0'):9;
    for(int dig=0;dig<=lim;++dig) {
        bool good=(ss.size()-i)%2==1?dig!=d:dig==d;
        if(good) c+=solve(bg and dig==lim, i-1, (j+pw[i]*dig)%m);
    }
    return c;
}
mint calc(string s) {
    reverse(all(s));
    ss = s;
    int n = s.size();
    pw[0]=1;
    for(int i=1;i<n;++i) {
        (pw[i]=pw[i-1]*10)%=m;
    }
    for(int k=0;k<2;++k) for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            dp[k][i][j].d=-1;
        }
    }
    return solve(true,n-1,0);
}
int main() {
    cin >> m >> d;
    string a; cin >> a;
    string b; cin >> b;
    auto tmp = calc(b);
    isA=true;
    tmp-=calc(a);
    cout << tmp;
}