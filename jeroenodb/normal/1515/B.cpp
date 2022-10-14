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
#define no {cout << "NO\n"; continue;}
#define yes {cout << "YES\n"; continue;}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n%2==1) no
        n/=2;
        int r = round(sqrt(n));
        if(r*r!=n) {
            int halfs = round(sqrt(n/2));
            if(halfs*halfs*2==n) {
                yes
            } else no
        } else {
            yes
        }
    }
}