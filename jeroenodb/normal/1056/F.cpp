// #pragma GCC optimize ("O3","fast-math")
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
const int mxN = 1e5+1;
const double oo = INFINITY;
typedef double FL;
FL dp[101][10001];
#define rep(i,n) for(int i=0;i<n;++i)

void cmin(FL& a, FL b) {a=min(a,b);}
const FL F = 1.0/0.9;
template<typename F> double minimize(double lo, double hi, F f, int iter=33) { // minimizes unimodal function
    auto mix=[&](double mx) {
        return (1.0-mx)*lo + mx*hi;
    };
    double res=oo;
    for(int rep=0;rep<iter;++rep) {
        double m1 = mix(0.4), m2 = mix(0.6);
        auto f1 = f(m1), f2 = f(m2);
        res = min({res,f1,f2});
        if(f1 < f2) hi=m2;
        else lo = m1;
    }
    // debug(lo);
    return res;
}
void solve() {
    int n; cin >> n;
    double c,t; cin >> c >> t;
    auto clear = [&]() {
        for(int i=0;i<=100;++i) fill_n(dp[i],10001,oo);
    };
    clear();
    dp[0][0]=0;
    vector<pi> ps(n);
    for(auto& [a,p] : ps) cin >> a >> p;
    sort(all(ps));
    int sm=0;
    for(int o=0;o<n;++o) {
        auto& [a,p] = ps[o];
        for(int num=o;num>=0;--num) {
            int lim = min(sm+1,num*10+1);
            rep(score, lim) {
                auto ct = dp[num][score];
                if(ct==oo) continue;
                cmin(dp[num+1][score+p], ct*F + a);
            }
        }
        sm+=p;
    }
    int ans = 0;
    rep(num, n+1) {
        if(num==0) continue;
        rep(score, num*10+1) {
            double ct = dp[num][score];
            if(ct==oo) continue;
            ct*=F;
            auto f = [&](double x) {
                return ct/(1+x*c) + x;
            };
            auto total = minimize(0.0,t,f);
            if(total+num*10<=t) {
                ans=max(ans,score);
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }

    
}