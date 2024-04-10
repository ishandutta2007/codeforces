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
array<ll,3> extendedgcd(ll a,ll b) {
    auto oa=a,ob=b;
    ll x=0,y=1,u=1,v=0;
    while(a!=0) {
        auto q=b/a,r=b%a;
        auto m=x-u*q,n=y-v*q;
        b=a, a=r, x=u,y=v,u=m,v=n;
    }
    assert(oa*x+ob*y==b);
    return {x,y,b};
    // a*x+b*y = b
}
int main() { 
    int n,m; cin >> n >> m;
    vector<bool> allowed(m,true);
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        allowed[a]=false;
    }
    map<int,vi> mp;
    for(int i=0;i<m;++i) if(allowed[i]) {
        mp[gcd(m,i)].push_back(i);
    }
    vi dp(m+1);
    vi par(m+1,-1);
    for(int i=m;i>=0;--i) {
        if(!mp.count(i)) continue;
        auto it = mp.upper_bound(i);
        dp[i] = 0;
        while(it!=mp.end()) {
            if(it->first % i == 0) {
                int tmp = +dp[it->first];
                if(tmp>dp[i]) {
                    dp[i]=tmp;
                    par[i]=it->first;
                }
            }
            ++it;
        }
        dp[i]+=mp[i].size();
    }
    auto best = max_element(all(dp))-dp.begin();
    vi res;
    while(best!=-1) {
        for(auto i : mp[best]) res.push_back(i);
        best=par[best];
    }
    int prev=1;
    cout << res.size() << '\n';
    for(auto& i : res) {
        int g = gcd(prev,m);
        int a = prev/g, b = i/g;
        ll ainv = extendedgcd(a,m/g)[0] % m;
        // solve a*x = b mod m/g 
        // x = b * a^(-1)
        ainv = (ainv+m)%m;
        cout << (ainv* b)%m << ' ';
        prev=i;
    }
}