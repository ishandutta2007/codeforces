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
    int n; cin >> n;
    string s; cin >> s;
    string a(n,'?'),b(n, '?');
    int ones=0, zeros = 0;
    for(int i=0;i<n;++i) {
        if(s[i]=='0') ones++;
        else zeros++;
    }
    if(ones&1) {
        cout << "NO\n";
        return;
    }
    int z=0,ab=0,bb=0 , o=0;
    for(int i=0;i<n;++i) {
        if(s[i]=='1') {
            if(z>=zeros/2) {
                a[i] = b[i]=')';ab--,bb--;
            } else {
                a[i] = b[i] = '(';ab++,bb++;
            }
            z++;
        } else {
            if(o&1) {
                a[i]='('; ab++;
                b[i]=')'; bb--;
            } else {
                a[i]=')'; bb++;
                b[i]='('; ab--;
            }
            o++;
        }
        if(ab<0 or bb<0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n" << a << '\n' << b << '\n';


}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}