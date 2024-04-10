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
        int n; cin >> n;
        vi res(n);
        int y=3<<29;
        
        for(int i=0;i<n-1;++i) {
            res[i]=i;
            y^=i;
        }
        res[0]|=1<<30;
        res[1]|=1<<29;
        res[n-1]=y;
        int x[2] = {};
        for(int i=0;i<n;++i) {
            x[i%2]^=res[i];
        }
        assert(x[0]==x[1]);
        assert(set<int>(all(res)).size()==n);
        cout << res  << '\n';
    }
}