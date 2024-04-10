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
        int n,k; cin >> n >> k;
        vi p(n); for(int& i:p) cin >> i;
        ll lo = 0, hi = 1e18/k;
        while(lo<hi) {
            ll mid = (lo+hi)/2;
            ll sm = mid+p[0];
            bool bad = false;
            for(int i=1;i<n;++i) {
                if((ll)p[i]*100> k*sm) {
                    bad = true;
                    break;
                }
                sm+=p[i];
            }
            if(bad) {
                lo=mid+1;
            } else {
                hi=mid;
            }
        }
        cout << lo << endl;
        
    }
}