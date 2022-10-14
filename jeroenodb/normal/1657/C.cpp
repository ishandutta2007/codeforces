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
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    reverse(all(s));
    int c=0,r=n;
    while(s.size()>1) {
        if(s.back()=='(') {
            r-=2;
            c++;
            s.pop_back(),s.pop_back();
        } else {
            int tmp=1;
            s.pop_back();
            while(!s.empty() and s.back()!=')') {
                s.pop_back();
                tmp++;
            }
            if(!s.empty()) {
                s.pop_back();
                tmp++;
                r-=tmp;
                c++;
            }
        }
    }
    cout << c << ' ' << r << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}