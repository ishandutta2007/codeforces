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
ll solve() {

    string a,s; cin >> a >> s;
    a= "000000000000000000000000"+a;
    int n = s.size();
    int j = a.size()-1;
    
    bool prevbad=false;
    ll ans = 0;
    ll pw=1;
    for(int i=n-1;i>=0;--i) {
        if(prevbad) {
            if(s[i]=='0') return -1;
            int dig = (s[i]-'0')*10+s[i+1]-a[j];
            if(dig>=10) return -1;
            ans+=pw*dig, pw*=10,--j;
            prevbad=false;
        } else {
            if(s[i]>=a[j]) {
                ans+=pw*(s[i]-a[j]);
                pw*=10;
                prevbad=false;
                --j;
            } else prevbad=true;
        }
    }
    if(j>=24) return -1;
    return ans;
}
int main() {
    int t; cin >> t;
    while(t--) {
        auto tmp = solve();
        cout << tmp << '\n';
    }
}