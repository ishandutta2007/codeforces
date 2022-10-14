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
// c&m +c c>=a
int f(int m, int a) {
    int ans = (a&m) + a;
    for(int i=27;i>=0;--i) {
        // want to cancel
        if(m& (1<<i)) {
            if(a& 1<<i) {
                int aa = a&(~((1<<(i+1))-1));
                aa+=2<<i;
                ans = min(ans,(aa&m)+aa);
            }
            
        }
    }
    return ans-a+1;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int a,b; cin >> a >> b;
        // b-a upperbound
        // a|b >= max(a,b), then only need to add b+++
        int ans = b-a;
        for(int c=b;c<=2*b;++c) {
            ans = min(ans, f(~c,a) + c-b );
        }
        cout << ans << '\n';
    }
}