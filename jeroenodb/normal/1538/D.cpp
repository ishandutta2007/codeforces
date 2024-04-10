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
int primefac(int n) {
    int res=0;
    for(int i=2;i*i<=n;++i) {
        while(n%i==0) {
            res++;
            n/=i;
        }
    }
    res+=n>1;
    return res;
}
bool solve() {
    int a,b,k; cin >> a >> b >> k;
    if(k>100) return false;
    if(k==1) {
        return a!=b and (a%b==0 or b%a==0);
    }
    int aa = primefac(a),bb = primefac(b);

    return aa+bb>=k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cout << (solve()?"YES\n":"NO\n");
    }
}