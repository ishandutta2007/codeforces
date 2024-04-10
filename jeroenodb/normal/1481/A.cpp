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
    int x,y; cin >> x >> y;
    string s; cin >> s;
    int cnt[4] = {};
    for(char c: s) {
        if(c=='U') {
            cnt[0]++;
        } else if(c=='D') {
            cnt[1]++;
        } else if(c=='R') {
            cnt[2]++;
        } else {
            cnt[3]++;
        }
    }
    if(x>0) {
        if (cnt[2] < x) return false;
    } else if (cnt[3] < -x) return false;
    if(y>0) {
        if (cnt[0] < y) return false;
    } else if (cnt[1]<-y) return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cout << (solve()?"YES\n":"NO\n");
    }
}