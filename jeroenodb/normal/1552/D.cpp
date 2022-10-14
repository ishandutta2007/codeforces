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
multiset<int> s;
bool rec(int i, vi& a, ll sm=0) {
    if(i==a.size()) {
        return s.find(sm)!=s.end();
    }
    s.insert(a[i]);
    if(rec(i+1,a,sm)) return true;
    s.erase(a[i]);
    if(rec(i+1,a,sm+a[i])) return true;
    return rec(i+1,a,sm-a[i]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        s.clear();
        vi a(n); for(auto& i : a) cin >> i, s.insert(i);
        cout << (rec(0,a)?"YES\n":"NO\n");

    }
}