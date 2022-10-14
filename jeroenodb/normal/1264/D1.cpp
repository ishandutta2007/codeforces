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
const int mxN = 3e3+1, oo = 1e9;
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
int pref[mxN]; // prefix sum for ?'s
mint pw[mxN];
mint dp[mxN][mxN];
string s;
mint solve(int l, int r) {
    if(l>=r) return 0;
    auto& c = dp[l][r];
    if(c.d!=-1) return c;
    c=0;
    if(s[l]!=')' and s[r]!='(') {
        int ques = pref[r]-pref[l+1];
        c+=pw[ques];
        c+=solve(l+1,r-1);
    }
    if(s[l]!='(' and s[r]!=')') {
        c=c-solve(l+1,r-1);
    } 
    if(s[l]!='(') {
        c+=solve(l+1,r);
    } 
    if(s[r]!=')') {
        c+=solve(l,r-1);
    }
    return c;
}
int main() {
    cin >> s;
    int n =s.size();
    for(int i=1;i<=n;++i) {
        pref[i]=pref[i-1]+(s[i-1]=='?');
    }
    pw[0]=1;
    for(int i=1;i<mxN;++i) pw[i]=pw[i-1]*2;
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) dp[i][j].d=-1;
    }
    cout << solve(0,n-1).d;
}