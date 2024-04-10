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
const int store=2e7 + 1;
bitset<store> sieve;
int factor[store];
void makesieve() {
    sieve[1] = true;
    for(int i = 2; i <= store/2;++i) {
        if(!sieve[i]) {
            for(int j = i*2;j<store;j+=i) {
                sieve[j] = true;
                factor[j]++;
            }
        } 
    }
}
int c,d;
inline int solve(int y) {
    int tmp = y+d;
    if(tmp%c!=0) {
        return 0;
    }
    tmp/=c;
    return 1<<(!sieve[tmp]+factor[tmp]);
}
int main() {
    makesieve();
    int t; cin >> t;
    while(t--) {
        int x; cin >> c >> d >> x;
        ll ans = 0;

        for(int i=1;i*i<=x;++i) {
            if(x%i==0) {
                ans+=solve(i);
                int tmp = x/i;
                if(tmp!=i) ans+=solve(tmp);
            }
        }
        cout << ans << '\n';
    }
}