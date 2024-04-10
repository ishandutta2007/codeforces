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
void cmin(int& a, int b){a=min(a,b);}
void solve() {
    int n; cin >> n;
    string s,t; cin >> s >> t;
    for(int i : {0,1}) {
        while(s.back()=='.' and t.back()=='.') {
            s.pop_back();
            t.pop_back();
        }
        reverse(all(s));
        reverse(all(t));
    }
    array<int,4> dp = {oo,};
    n=s.size();
    
    for(int i=0;i<n;++i) {
        array<int,4> ndp = {oo,oo,oo,oo};
        cmin(ndp[3],*min_element(all(dp))+2);
        if(t[i]=='.') cmin(ndp[1],min(dp[3],dp[1])+1);
        if(s[i]=='.') cmin(ndp[2],min(dp[3],dp[2])+1);
        dp=ndp;
    }

    cout << *min_element(all(dp))-1 << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}