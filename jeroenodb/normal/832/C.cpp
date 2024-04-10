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
    ll s;
    int n; cin >> n >> s;
    struct person {
        ll x,v;
        short t;
        void read() {
            cin >> x >> v >> t;
        }
        bool operator<(const person& o) {
            return make_pair(x, t) <make_pair(o.x,o.t);
        }
    };
    vector<person> ps(n);
    for(auto& i : ps) i.read();
    sort(all(ps));
    double lo = 0, hi = 1e6;
    auto good = [&](double timelimit) {
        ll best=-INFINITY;
        bool withHelp[2] = {}, noHelp[2] = {};
        for(auto i : ps) {
            if(i.t==1) {
                // check if uberhaupt possible
                if(timelimit*(i.v+s)>=i.x) {
                    withHelp[0]=true;
                    if(timelimit*i.v>=i.x) {
                        if(withHelp[1]) return true;
                        best = oo;
                    } else {
                        if(noHelp[1]) return true;
                        auto tmp = (i.x*(i.v-s)+timelimit*(s*s-i.v*i.v))/s;
                        best = max(best, (ll)floor(tmp+i.x));
                    }
                }
            } else {
                i.x = 1e6-i.x;
                if(timelimit*(i.v+s)>=i.x) {
                    withHelp[1]=true;
                    if(timelimit*i.v>=i.x) {
                        noHelp[1]=true;
                        if(withHelp[0]) return true;
                    } else {
                        auto tmp = (i.x*(i.v-s)+timelimit*(s*s-i.v*i.v))/s;
                        i.x = 1e6-i.x;
                        if(i.x-tmp <= best) return true;
                    }
                }
            }
        }
        return false;
    };
    while(abs(hi-lo)>4e-7) {
        auto mid = 0.5*(lo+hi);
        if(good(mid)) hi = mid;
        else lo = mid;
    }
    cout << setprecision(15) << lo << '\n';
}