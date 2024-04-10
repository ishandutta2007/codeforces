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
int query(vi a) {
    cout << "? " << a << endl;
    int c,b; cin >> c >> b;
    return b;
}
int main() {
    int n,k; cin >> n >> k;
    vi know(n+1,-1);
    map<int,int> cnt;
    for(int i=0;i<k+1;++i) {
        vi a;
        for(int j=0;j<=k;++j) {
            if(j!=i) a.push_back(j+1);
        }
        cnt[query(a)]++;
    }
    cout << "! " << cnt.rbegin()->second << endl;

}