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
class mint {
public:
    int d;
    mint () {d=0;}
    mint (long long _d) : d(((_d%MOD)+MOD)%MOD){};
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
    friend mint& operator-=(mint& a, const mint& o) {
        a.d-=o.d;
        if(a.d<0) a.d+=MOD;
        return a;
    }
};
const int mxF=3e5;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    string s; cin >> s;
    int k=0;
    vi cnt;
    {
    map<char,int> mp;
    for(char& c: s) {
        if(mp.count(c)) c=mp[c];
        else {
            c=mp[c]=mp.size();
            cnt.push_back(0);
        }
        cnt[c]++;
    }
    k=mp.size();
    }
    // knapsack/subset sum DP
    int n = s.size();
    vector<mint> full(n/2+1);
    mint ans[52][52];
    full[0]=1;
    for(int i=0;i<k;++i) {
        int w = cnt[i];
        for(int j=n/2;j>=w;--j) {
            full[j]+=full[j-w];
        }
    }
    for(int a=0;a<k;++a) {
        auto dp = full;
        int w=cnt[a];
        for(int j=w;j<=n/2;++j) {
            dp[j]-=dp[j-w];
        }
        for(int b=a+1;b<k;++b) {
            mint res=0;
            int w = cnt[b];
            int sgn=1;
            for(int i=n/2;i>=0;i-=w) {
                res += dp[i]*mint(sgn);
                sgn*=-1;
            }
            ans[a][b]=res;
        }
    }
    mint w=fact[n/2]*fact[n/2], denum=1;
    for(int i=0;i<k;++i) denum=denum*fact[cnt[i]];
    w=w/denum;
    int q; cin >> q;
    for(int i=0;i<q;++i) {
        int x,y; cin >> x >> y,--x,--y;
        x=s[x],y=s[y];
        if(x>y) swap(x,y);
        if(x==y) {
            cout << (full[n/2]*w).d << '\n';
        } else {
            cout << (ans[x][y]*w*2).d << '\n';
        }
    }
}