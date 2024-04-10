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
bool solve() {
    int n; cin >> n;
    vector<string> a(n);
    for(auto& i : a) cin >> i;
    // check for 1 length subs
    for(auto i : a) {
        auto t = i;
        reverse(all(t));
        if(i==t) return true;
    }
    // check for 2 length subs
    set<string> s,s2;
    for(auto i : a) {
        if(s.count(i)) {
            return true;
        }
        if(i.size()==3) {
            if(s2.count(i.substr(1))) return true;
        }
        auto t = i;
        reverse(all(t));
        s2.insert(t);
        s.insert(t);
        if(t.size()==3) {
            s.insert(t.substr(1));
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        auto tmp = solve();
        if(tmp) cout << "YES\n";
        else cout << "NO\n";
    }
}