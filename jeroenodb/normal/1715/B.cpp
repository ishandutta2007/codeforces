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
void solve() {
    ll n,k,b,s; cin >> n >> k >> b >> s;
    vector<ll> a(n);
    // first distribute everything?
    ll use = max(0LL, (s-n*(k-1))/k);
    a[0]+=use*k;
    b-=use;
    s-=use*k;
    
    if(b<0) {
        cout << "-1\n";
        return;
    }
    a[0]+=b*k;
    s-=b*k;
    if(s<0) {
        cout << "-1\n";
        return;
    }
    for(int i=0;i<n;++i) {
        use = min(k-1,s);
        a[i]+=use;
        s-=use;
    }
    if(s>0) cout << "-1\n";
    else cout << a << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();

    }
}