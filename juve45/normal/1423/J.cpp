#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.first << ' ' << p.second << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<long long,long long>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define fi first
#define se second
#define Nmax 500005
const long double PI = acos(-1);
 
ll x,t;
long long dp[70][8];
 
long long asd(long long last) {
  if(last % 2 == 1)
    return last / 2;
  return 0;
}
 
static inline void sum(long long &a, long long b){
  a += b;
  if (a >= MOD) a -= MOD;
}
 
int main(){
  ios::sync_with_stdio(false);
 
  scanf("%d", &t);
  for (long long i=1;i<=t;i++){
    scanf("%lld", &x);
 
    long long last = x / 2 + 1;
    long long sum = 0;
    if(last % 2 == 1) sum += (last + 1) / 2, last--;

    long long f = (last / 2) % MOD;
    sum += 1LL * f * (f + 1);
    sum %= MOD;

    printf("%d\n", sum);

    // cout << dp[k][0] << '\n';
  }
  return 0;
}