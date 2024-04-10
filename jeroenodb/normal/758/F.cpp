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
const ll oo = 1e14;
int main() {
    int n,l,r; cin >> n >> l >> r;
    ll len = r-l+1;
    if(n==1) {
        cout << len << '\n';
        exit(0);
    }
    if(n==2) {
        cout << len*(len-1) << '\n';
        exit(0);
    }
    if(n>=1000) {
        cout << "0\n";
        exit(0);
    }
    auto mypow = [&](int i) {
        bool bad=false;
        ll pw=1;
        for(int j=0;j<n-1;++j) {
            if(r/i<pw) {
                bad=true;
                break;
            }
            pw*=i;
        }
        if(bad) return oo;
        return pw;
    };
    ll ans=0;
    for(ll i=1;;++i) {
        auto pwi = mypow(i);
        if(pwi==oo) break;
        for(ll j=1;j<i;++j) {
            auto pwj = mypow(j);
            if(pwj==oo) break;
            if(gcd(i,j)!=1) continue;
            int lo = l, hi = r*pwj/pwi;
            // a_0 is divisible by pwj
            int num = hi/pwj - (lo-1)/pwj;
            ans+=max(0, num);
        }
    }
    cout << ans*2 << '\n';

}