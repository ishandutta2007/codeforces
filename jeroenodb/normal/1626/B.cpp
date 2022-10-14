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
        string x; cin >> x;
        // last digits
        int n = x.size();
        string res;
        auto check = [&](int i) {
            string between= to_string(x[i]+x[i+1]-'0'*2);
            auto cur = x.substr(0,i)+between;
            if(i+2<n) cur+=x.substr(i+2);
            if(res.empty() or make_pair(res.size(),res)<make_pair(cur.size(),cur) ) res = cur;
        };
        check(n-2);
        check(0);
        for(int i=n-2;i>=0;--i) {
            if(x[i]+x[i+1]-'0'*2>=10) {
                check(i);
                break;
            }
        }
        cout << res << '\n';
    }
}