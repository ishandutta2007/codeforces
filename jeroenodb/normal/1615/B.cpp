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
int get(int i, int bit) {
    
    int res=0;
    int j = i& (~((1<<bit)-1));
    res = i-j+1;
    if(1<<bit & i) res=0;
    //  10100101101010000
    j>>=bit;
    j = (j+1)/2;
    return res + (j<<bit);
}
int main() {
    int t; cin >> t;
    while(t--) {
        int l,r; cin >> l >> r;
        int ans = oo;
        for(int b=0;r>>b > 0;++b) {
            ans = min(ans,get(r,b)-get(l-1,b));
        }
        cout << ans << '\n';
    }
}