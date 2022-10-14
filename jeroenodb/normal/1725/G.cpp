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
ll f(ll a) {
    return max(0LL, (a-4)/4) + max(0LL,(a-1)/2);
}
// 3^2-1^2=8
// 2^2-1%2
int main() {
    // b*b - a*a = x
    // (b-a)*(b+a)
    // 2*(b+b+2)
    // 4*b+4
    // 2*b+1
    // 4*(b*2+4)
    ll lo = 0,hi=1;
    ll n; cin >> n;
    while(f(hi)<n) {
        hi*=2;
    }
    while(lo<hi) {
        auto mid = (lo+hi)/2;
        if(f(mid)>=n) hi = mid;
        else lo = mid+1;
    }
    cout << lo << '\n';
}