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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(2*n); for(auto& i: a) cin >> i;
        sort(all(a));
        bool found = true;
        ll last = 0, blast=1e18;
        for(int i=2*n-2;i>=0;i-=2) {
            if(a[i]!=a[i+1]) {
                found = false;
                break;
            }
            auto tmp = a[i]-2*last;
            if(tmp%(i+2)!=0) {
                found = false;
                break;
            }
            ll b = tmp/=(i+2);
            // cout << b << ' ';
            if(b<=0) {
                found = false;
                break;
            }
            if(blast<=b) {
                found = false;
                break;
            }
            blast = b;
            last+=b;
        }
        cout << (found?"YES\n":"NO\n");
    }

}