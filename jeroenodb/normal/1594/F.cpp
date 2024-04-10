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
ll ceildiv(ll a, ll b) {
    return (a+b-1)/b;
}
int main() {
    int t; cin >> t;
    while(t--) {
        ll s,n,k; cin >> s >> n >> k;
        bool ans=false;

        if(s!=k) {
            // max size of a set S with integers in 0, ... , s
            // such that  i in S --> i+k not in S
            // and 0 in S, s in S
            // This condition is independent for each modular class
            ll maxlen=0;
            if(s%k==0) {
                // highest and lowest both in one class
                // Check if pattern 101010101 works or not
                if(s/k %2 ==0) maxlen+=ceildiv(s/k + 1,2);
                else maxlen+=ceildiv(s/k, 2); // parity between s and 0, is wrong.
                maxlen+=ceildiv(s/k, 2)*(k-1); // the rest of the modular classes
            } else {
                auto hi = s%k + 1, lo = k-hi;
                maxlen+=ceildiv(s/k+1,2)*hi;
                maxlen+=ceildiv(s/k,2)*lo;
            }
            // prefix sum array is one bigger than real number of pens.
            ans=maxlen-1>=n;
        }
        if(!ans) cout << "YES\n";
        else cout << "NO\n";
    }
}