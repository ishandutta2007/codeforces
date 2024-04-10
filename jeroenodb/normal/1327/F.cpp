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
const int mxN = 5e5+10, oo = 1e9;
typedef array<int,3> hint;
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
int one[mxN],mx[mxN];
mint dp[mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,m; cin >> n >> k >> m;
    vector<hint> hs(m);
    for(auto& [l,r,x]: hs) cin >> l >> r >> x;
    mint res=1;
    vector<mint> pw(n+10);
    pw[0]=1;
    for(int i=1;i<pw.size();++i) {
        pw[i]=pw[i-1]*2;
    }

    for(int b=0;b<k;++b) {
        // solve problem for this bit
        fill(one,one+n+2,0);
        fill(mx,mx+n+2,0);
        for(const auto [l,r,x]: hs) {
            if(1<<b & x) {
                one[l]++;
                one[r+1]--;
            }
        }
        for(int i=1;i<=n+1;++i) {
            one[i]+=one[i-1];
            one[i-1]=!one[i-1];
        }
        for(const auto [l,r,x]: hs) {
            if(!(1<<b & x)) {
                mx[r]=max(mx[r],l);
            }
        }
        dp[0]=1;
        for(int i=1;i<=n;++i) {
            mx[i]=max(mx[i],mx[i-1]); 
            dp[i]=0;
            if(one[i]) {
                dp[i]=dp[i-1];
                if(mx[i-1]) dp[i] = dp[i]-dp[mx[i-1]-1];
            }
            dp[i] += dp[i-1];
        }
        auto fact = dp[n];
        if(mx[n]) fact=fact-dp[mx[n]-1];
        res = res*fact;
    }
    cout << res.d << '\n';

}