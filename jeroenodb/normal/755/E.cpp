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
    int n,k; cin >> n >> k;
    if(n<=3 or (k!=2 and k!=3) or (k==2 and n==4)) {
        cout << "-1\n";
        exit(0);
    }
    cout << n-1 << '\n';
    if(k==2) {
        for(int i=1;i<n;++i) {
            cout << i << ' ' << i+1 << '\n';
        }
    } else if(k==3) {
        for(int i=1;i<=2;++i) {
            cout << i << ' ' << i+1 << '\n';
        }
        for(int j=4;j<=n;++j) {
            cout << "1 " << j << '\n';
        }
    }
}