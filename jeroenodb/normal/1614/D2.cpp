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
const int mxN = 1e5, oo = 1e9;
const int A = 2e7+1;
int cnt[A];
ll dp[A];
bitset<A> sieve;
int main() {
    int n; cin >> n;
    vi a(n);
    for(auto& i : a) {
        cin >> i;
        cnt[i]++;
    }
    vi primes; primes.reserve(int(7e6));
    for(int i = 2; i < A;++i) {
        if(!sieve[i]) {
            primes.push_back(i);
            for(int j = i*2,k=2;j<A;j+=i,k++) {
                sieve[j]=true;
            }
        }
        if(n<A/i) {
            cnt[i]=0;
            for(auto& j : a)  if(j%i==0) 
                cnt[i]++;
        } else {
            for(int j=i*2;j<A;j+=i) cnt[i]+=cnt[j];
        }
    }
    cnt[1]=n;
    for(int i=A-1;i>=1;--i) {
        dp[i] = cnt[i]*ll(i);
        for(auto p : primes) {
            if(i*p>=A) break;
            dp[i] = max(dp[i],dp[i*p]+(cnt[i]-cnt[i*p])*ll(i));
        }
    }
    cout << dp[1] << '\n';
}