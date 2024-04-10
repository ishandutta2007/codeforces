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
const int mxN = 2e5+1, oo = 1e9;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi p(n); for(int& i : p) cin >> i,--i;
        vi c(n); for(int& i : c) cin >> i,--i;
        vector<bool> visited(n);
        int ans = n;
        auto go = [&](vi& cyc, int k) {
            int m = cyc.size();
            for(int rot = 0;rot<k;++rot) {
                bool good = true;
                int base = c[cyc[rot]];
                for(int i = rot;i<m;i+=k) {
                    if(c[cyc[i]]!=base) {
                        good = false;
                        break;
                    }
                }
                if(good) return true;
            }
            return false;
        };
        auto checkcycle = [&](vi& cyc) {
            int m = cyc.size();
            vector<bool> good(m+1);
            for(int i=1;i<=m;++i) {
                if(m%i==0) 
                    good[i] = go(cyc, i);
            }
            for(int i=1;i<= min(m,ans);++i) {
                if(good[__gcd(i,m)]) {
                    ans = min(ans,i);
                } 
            }
        };
        for(int i=0;i<n;++i) {
            if(!visited[i]) {
                int at = i;
                vi cycle;
                do {
                    visited[at] = true;
                    cycle.push_back(at);
                    at = p[at];
                } while(!visited[at]);
                checkcycle(cycle);
            }
        }
        cout  << ans << '\n';
    }

}