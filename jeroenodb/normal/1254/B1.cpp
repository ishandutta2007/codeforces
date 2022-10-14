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
int main() {
    int n; cin >> n;
    ll sm=0, ans = 1e18;
    vi a(n);
    for(auto& i : a) cin >> i,sm+=i;
    auto cand = [&](ll f) {
        ll pref=0,cur=0;
        for(auto i : a) {
            pref+=i;
            pref%=f;
            cur+= min(pref,f-pref);
        }
        ans=min(ans,cur);
    };
    for(ll f=2;f*f<=sm;++f) {
        if(sm%f==0) {
            while(sm%f==0) sm/=f;
            cand(f);
        }
    }
    if(sm!=1) cand(sm);
    cout << (ans==1e18?-1:ans) << '\n';
}