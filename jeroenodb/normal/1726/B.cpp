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
void solve() {
    int n,m; cin >> n >> m;

    if(n>m) {
        cout << "No\n";
        return;
    }
    if(m%n==0) {
        cout << "Yes\n";
        for(int i=0;i<n;++i) cout << m/n << " ";
        cout << '\n';
        return;
    }
    // put all ones?
    if(n%2==1) {
        cout << "Yes\n";
        int left = m-(n-1);
        for(int i=0;i<n-1;++i) cout << "1 ";
        cout << left << '\n';
    } else if(m%2==0) {
        cout << "Yes\n";
        int left = m-(n-2);
        for(int i=0;i<n-2;++i) cout << "1 ";
        cout << left/2 << ' ' << left/2 << '\n';
    } else cout << "No\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}