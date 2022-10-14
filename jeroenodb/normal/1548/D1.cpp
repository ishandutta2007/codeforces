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
ll ch3(int n) {
    return (ll)n*(n-1)*(n-2)/6;
}
ll ch2(int n) {
    return (ll)n*(n-1)/2;
}
int main() {
    int n; cin >> n;
    int a[4] = {};
    for(int i=0;i<n;++i) {
        int x,y; cin >> x >> y;
        a[(x%4)+(y%4)/2]++;
    }
    ll ans = ch3(n);
    for(int i=0;i<4;++i) {
        ans-=(ll)a[i]*a[(i+1)%4]*a[(i+2)%4];
    }
    cout << ans << '\n';
}