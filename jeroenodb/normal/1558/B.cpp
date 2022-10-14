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
long long MOD=1e9+7;
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
int main() {
    int n;
    cin >> n >> MOD;
    vector<mint> dp(n+1);
    dp[1]=1;
    mint pref=1,pref2=0;
    vi nxt(n+1,-1);
    vi head(n+1,-1);
    for(int i=2;i<=n;++i) {
        if(i*2<=n) {
            nxt[i]=head[i*2];
            head[i*2]=i;
        }
        pref2+=dp[1];
        for(int u =head[i]; u!=-1;) {
            int id = i/u;
            pref2 = pref2 - dp[id-1];
            pref2+=dp[id];
            
            int want = (id+1) * u;
            int nu = nxt[u];
            if(want<=n){
                nxt[u]=head[want];
                head[want] = u;
            } 
            u=nu;
        }
        dp[i]+=pref;
        dp[i]+=pref2;
        pref+=dp[i];
    }
    cout << dp[n].d;

}