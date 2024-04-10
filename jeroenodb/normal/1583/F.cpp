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
    int n,k; cin >> n >> k;
    int cols = 16;
    auto digs = [&](int a) {
        vi res;
        for(int i=0;i<cols;++i) {
            res.push_back(a%k);
            a/=k;
        }
        return res;
    };
    vi res;
    for(int i=0;i<n;++i) {
        auto d1 = digs(i);
        for(int j=i+1;j<n;++j) {
            auto d2 = digs(j);
            for(int a=cols-1;a>=0;--a) {
                if(d1[a]!=d2[a]) {
                    res.push_back(a+1);
                    break;
                }
            }
        }
    }
    cout << *max_element(all(res)) << '\n';
    cout << res << '\n';
}