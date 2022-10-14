// #pragma GCC optimize("Ofast")
// #pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")
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

const int n = 3e8;
bitset<n+1> s;
const int store=n+1;
bitset<store/2> sieve={};
int ans=0,l,r;
int lim = sqrt(n)+1;
void makesieve() {

    for(int i = 3; i < lim;i+=2) {
        if(!sieve[i/2]) {
            int step = 2*i;
            for(int j = i*3;j<store;j+=step) {
                sieve[j/2]=true;
            }
        }
    }
    for(int i = s._Find_next(l-1);i<=r;i=s._Find_next(i)) {
        if(i%2==1 and !sieve[i/2]) 
            ans++;
    }
}
int main() {
    cin >> l >> r;
    if(l<=2 and 2<=r) ans++;
    for(int i=1;i*i<=n;++i) {
        int ii = i*i;
        for(int j=i+1;ii+j*j<=n;j+=2) {
            s[ii+j*j]=true;
        }
    }
    debug("done squaring");
    makesieve();
    cout << ans << '\n';
}