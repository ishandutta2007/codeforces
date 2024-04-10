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
const int mxF=1e5;
mint fact[mxF], ifact[mxF];
mint c(int a, int b) {
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
int main() {
    precomp();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,n; cin >> h >> w >> n;
    vector<bool> a(h), b(w);
    while(n--) {
        array<int,4> c;
        for(auto& i : c) cin >> i,--i;
        a[c[0]]=a[c[2]]=true;
        b[c[1]]=b[c[3]]=true;
    }
    struct DP {
        vector<mint> dp[3];
        int cnt=0;
        mint query(int ones, int twos) {
            int left = cnt-twos*2;
            if(ones<=left) {
                return dp[0][twos]*c(left,ones);
            } return 0;
        }
        DP(const vector<bool>& bad) {
            int n = bad.size();
            cnt = count(all(bad),false);
            for(int i=0;i<3;++i) dp[i].resize(n+1);
            dp[0][0]=dp[1][0]=1;
            for(int i=2;i<=n;++i) {
                dp[i%3]= dp[(i-1)%3];
                if(!bad[i-1] and !bad[i-2]) {
                    for(int j=n;j>=1;--j) {
                        dp[i%3][j]+=dp[(i-2)%3][j-1];
                    }
                }
            }
            dp[0] = dp[n%3];
        }
    };
    DP rdp(a), cdp(b);
    mint ans=0;
    for(int i=0;i<=min(h,w);++i) {
        for(int j=0;j<=i;++j) {
            ans+=rdp.query(j,i-j)*cdp.query(i-j,j)*fact[i-j]*fact[j];
        }
    }
    cout << ans.d << '\n';
}