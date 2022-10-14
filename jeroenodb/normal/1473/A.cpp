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
        int n,d; cin >> n >> d;
        vi a(n); for(int& i: a) cin >> i;
        sort(all(a));
        if(a.back()<=d) {
            cout << "YES\n";
            continue;
        }
        if(n<3) {
            cout << "NO\n";
            continue;
        }
        int leastsum = a[0]+a[1];
        if(leastsum>d ) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}