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
ll gcdsum(ll n) {
    ll memon = n;
    ll sm = 0;
    while(n) {
        sm+=n%10;
        n/=10;
    }
    return __gcd(memon,sm);
}
int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        while(gcdsum(n)==1) {
            ++n;
        }
        cout << n << '\n';
    }
}