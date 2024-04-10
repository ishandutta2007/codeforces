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
vi l[2][2];
string s; int n;
int solve(int at, bool right, bool flip) {
    auto& a = l[right][flip][at];
    if(a != -1) {
        return a;
    }

    if(at<n and right and ((s[at]=='R') ^ flip)) {
        return a = solve(at+1,1,!flip);
    }
    if(at and !right and ((s[at-1]=='L') ^ flip)) {
        
        return a = solve(at-1,0,!flip);
    }

    return a = at+1;
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;

        for(int i: {0,1}) {
            for(int j:{0,1}) {
                l[i][j].clear();
                l[i][j].assign(n+1,-1);
            }
        }

        for(int i=0;i<=n;++i) {
            cout << solve(i, 1,0)-solve(i,0,0)+1 << ' ';
        } cout << endl;

        
        
    }
}