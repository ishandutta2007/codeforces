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
        vi a(n); for(auto& i : a) cin >> i;
        int prev=0;
        a.insert(a.begin(),0);
        a.push_back(0);
        ll ans=0;
        for(int i=1;i<n+2;++i) {
            ans+=abs(a[i]-prev);
            prev=a[i];
        }
        for(int i=1;i<n+1;++i) {
            if(a[i]>a[i-1] and a[i]>a[i+1]) {
                ans-=a[i]-max(a[i-1],a[i+1]);
            }
        }
        cout << ans << '\n';
    }
}