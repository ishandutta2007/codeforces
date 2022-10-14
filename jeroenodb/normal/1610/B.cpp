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
bool check(vi a, int c) {
    int i=0,j=a.size()-1;
    while(i<j) {
        if(a[i]==a[j]) {
            ++i,--j;
            continue;
        }
        if(a[i]==c) ++i;
        else if(a[j]==c) --j;
        else return false;
    }
    return true;
}
bool solve() {
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    vi b = a; reverse(all(b));
    if(a==b)
        return true;
    int i=0;
    while(a[i]==b[i]) ++i;
    return check(a, a[i]) or check(a,b[i]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        auto tmp = solve();
        if(tmp) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}