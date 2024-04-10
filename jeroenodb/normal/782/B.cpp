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
    int n; cin >> n;
    int mn = oo, mx=0;
    vi x(n); for(int& i: x) {
        cin >> i;
        mn = min(mn,i);
        mx = max(mx,i);
    }
    vi v(n); for(int& i: v) cin >> i;

    auto good = [&](double t) {
        double l = x[0]-v[0]*t, r = x[0]+v[0]*t;
        for(int i=1;i<n;++i) {
            double left = x[i]-v[i]*t, right = x[i]+v[i]*t;

            l = max(l,left);
            r = min(r,right);
            if(l>r) return false;
        }
        return true;
    };
    double lo = 0, hi = mx-mn;
    while(hi-lo>5e-7) {
        double mid = 0.5*(lo+hi);
        if(good(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << setprecision(10) <<  0.5*(lo+hi) << '\n';
}