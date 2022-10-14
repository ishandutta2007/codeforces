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
        int x,y; cin >> x >> y;
        if(y<x) {
            cout << ll(oo)*x + y << '\n';
        } else if(y==x) {
            cout << x << '\n';
            // y>=x
            // both are even

        } else {
            auto f = [&](ll n) {
                return n+ n%x;
            };
            ll lo = y/2+1, hi = y;
            auto maybe = (lo+x-1)/x * x;
            if(f(maybe)<f(lo)) 
                lo = maybe;
            while(lo<hi) {
                ll n = lo + (hi-lo)/2;
                ll lhs = n+n%x;
                if(lhs<y) {
                    lo = n+1;
                } else hi = n;
            }
            assert(lo%x==y%lo);
            cout << lo << '\n';
        }
    }
}