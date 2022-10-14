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
        vi a(n);
        ll total = 0, ans=0;
        for(int& i : a) {
            cin >> i;
            total+=i;
        }
        if(n<=2) {
            if(n==1) ans = 1;
            else {
                if(a[0] == a[1]) {
                    ans=1;
                } else {
                    ans=2;
                }
            }
            cout << ans << '\n';
            continue;
        }
        vector<ll> pref(n+1);
        for(int i=1;i<=n;++i) {
            pref[i] = a[i-1];
            if(i>=2) pref[i]+=pref[i-2];
        }
        auto range = [&](int l, int r) {
            return pref[r+1]-pref[max(l-1,0)];
        };

        auto solve = [&](int aa, int bb, ll got, bool nope=false) {
            for(int j=bb;j>=aa-1;--j) {
                int l=0, r = 1 + (j-aa+1)/2;
                if(nope and j==bb) r = min(r,1);
                int hi  = r;
                while(l<r) {
                    int mid = (l+r)/2;
                    ll extra = range(j-mid*2+1,j-1);
                    if((got+extra)*2<=total) {
                        l=mid+1;
                    } else {
                        r = mid;
                    }
                }
                ans+=hi - r;
                got+=a[j];
            }
        };
        solve(1,n-2,0,true);
        solve(2,n-2, a[0],true);
        solve(2,n-2, a[0]+a.back());
        solve(1,n-2, a.back());
        ll cur=a[0];
        for(int i=1;i<n;++i) {
            cur+=a[i];
            if(cur*2>total) ans++;
        }
        cout << ans%998244353 << '\n';
        
    }

}