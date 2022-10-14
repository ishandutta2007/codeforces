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
bool solve() {
    int n,k; cin >> n >> k;
    vector<ll> s(k);
    for(auto& i : s) cin >> i;
    if(k==1) return true;
    ll l = s[1]-s[0];
    if((n-k+1)*l < s[0]) return false;
    vector<ll> b(k-1);
    for(int i=0;i+1<k;++i) {
        b[i]=s[i+1]-s[i];
    }
    return is_sorted(all(b));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        if(solve()) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}