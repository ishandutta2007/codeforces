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
    double r,v;
    int n; cin >> n >> r >> v;
    while(n--) {
        int s,ff; cin >> s >> ff;
        int d = ff-s;
        auto f = [&](double t) {
            double offset = (v*t)/(r*2);
            return v*t+abs(sin(offset))*r*2;
        };
        double lo = 0, hi = 1;
        while(f(hi)<d) 
            hi*=2;
        for(int rep=0;rep<60;++rep) {
            auto mid = 0.5*(lo+hi);
            auto myf = f(mid);
            if(myf<d) lo = mid;
            else hi = mid;
        }
        cout << setprecision(15) << lo << '\n';
    }
}