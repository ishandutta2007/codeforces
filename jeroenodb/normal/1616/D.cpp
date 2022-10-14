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
void cmax(int& a, int b) {a=max(a,b);}

void mysolve() {
    int n; cin >> n;
    vi a(n); 
    for(auto& i : a) 
        cin >> i;
    int x; cin >> x;
    vi dp(n+1,-oo);
    dp[0]=0;
    dp[1]=1;
    int best=-oo;
    int j=0;
    for(int i=1;i<n;++i) {
        if(a[i]+a[i-1]>=2*x) {
            if(i<2 or a[i]+a[i-1]+a[i-2]<3*x) {
                j=i-1;
                best = dp[max(i-2,0)]-i+1;
            }
        } else j=i, best=-oo;
        best = max(best, dp[max(0,i-1)]-i);
        dp[i+1] = best+i+1;
        dp[i+1]= max(dp[i+1],dp[i]);
    }
    // debug(dp);
    cout << *max_element(all(dp)) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) 
        mysolve();
}