#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define dbg(x) cerr<<#x": "<<(x)<<endl
#define dbg_p(x) cerr<<#x": "<<(x).first<<' '<<(x).second<<endl
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<endl;}
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define INF 2000000010
#define MOD 1000000007
#define ST_SIZE 1048600
#define QMAX 
#define NMAX 

template<typename T1, typename T2>
ostream& operator <<(ostream &out, const pair<T1, T2> &item) {
  out << '(' << item.first << ", " << item.second << ')';
  return out;
}

template<typename T>
ostream& operator <<(ostream &out, const vector<T> &v) {
  for(const auto &item : v) out << item << ' ';
  return out;
}

ll t, n, k;

bool ok(ll a, ll b, ll x) {
  // dbg(x);
  if(!x) return true;
  
  ll nr = 0, rest = 0;
  if(a <= x) {
    a *= (n + 1) / 2;
    nr += a / x;
    rest += a % x;
  } else {
    nr += (n + 1) / 2;
  }
  
  // dbg(nr);
  // dbg(rest);
  
  if(b <= x) {
    b *= n / 2;
    nr += b / x;
    rest += b % x;
  } else {
    nr += n / 2;
  }
  
  // dbg(nr);
  // dbg(rest);
  
  return nr + rest / x >= k;
}

int main()
{
  ios_base::sync_with_stdio(false);
  
  ll a, b, l, r, mid;
  
  cin >> t >> n >> a >> b >> k;
  
  for(l = 0, r = t; l < r; ) {
    mid = (l + r + 1) / 2;
    if(ok(a, b, mid)) l = mid;
    else r = mid - 1;
  }
  
  cout << l << '\n';
  
  return 0;
}