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
const int mxN = 2005, oo = 1e9;
bitset<mxN> dp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n); for(auto& i : a) cin >> i;
        int lo=*max_element(all(a)), hi = mxN-1;
        auto good= [&](int mid) {
            bitset<mxN> mask;
            for(int i=0;i<mid;++i) mask[i]=true;
            dp.reset();
            for(int i=a[0];i<mid;++i) dp[i]=true;
            for(int i=1;i<n;++i) {
                dp = (dp<<a[i]|dp>>a[i])&mask;
            }
            return dp.any();
        };
        while(lo<hi) {
            int mid = (lo+hi)/2;
            if(good(mid)) {
                hi=mid;
            } else lo=mid+1;
        }
        cout << lo-1 << '\n';
    }
}