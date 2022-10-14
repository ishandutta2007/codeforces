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
        vi a(n),b(n);
        for(auto& i : a) cin >> i;
        for(auto& i : b) cin >> i;
        sort(all(a)), sort(b.rbegin(), b.rend());
        int i=n/4, j = n-n/4;
        int me = accumulate(a.begin()+i,a.end(),0);
        int him = accumulate(b.begin(),b.begin()+j,0);
        int ans = 0;
        while(me<him) {
            ans++,n++;
            a.push_back(100);
            me+=100;
            b.push_back(0);
            while(j<n-n/4) {
                him+=b[j++];
            }
            while(i<n/4) {
                me-=a[i++];
            }
        }
        cout << ans << '\n';
    }
}