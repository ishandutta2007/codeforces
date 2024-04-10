#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int Mod = 998244353;
int add(int a, int b){a += b; return a<Mod ? a : a-Mod;}
int sub(int a, int b){a -= b; return a<0 ? a+Mod : a;}
int mul(int a, int b){return (int)((ll)a*b%Mod);}
int pot(int a, int b){
  int r = 1;
  while (b){
    if (b&1) r = mul(r, a);
    a = mul(a, a), b >>= 1;
  } return r;
}

int k;
int digits[20];
int len;
pii memo[20][1<<10][2][2];

pii dp(int pos, int bit, int bound, int zeroes){
  if (pos == len) return {__builtin_popcount(bit) <= k, 0};
  pii &r = memo[pos][bit][bound][zeroes];
  int &cnt = r.x;
  int &sum = r.y;
  if (cnt != -1) return r;
  cnt = sum = 0;

  int limit = bound ? digits[pos] : 9;
  REP(d,limit+1){
    pii nr = dp(pos+1, bit | ((1 && !(zeroes && d == 0))<<d), bound && d == digits[pos], zeroes && d == 0);
    int ncnt = nr.x;
    int nsum = nr.y;
    
    cnt = add(cnt, ncnt);
    sum = add(sum, nsum);
    sum = add(sum, mul(ncnt, mul(d, pot(10, len-pos-1))));
  }

  return r;
}

int f(ll limit){
  len = 0;
  memset(memo, -1, sizeof memo);
  while (limit) digits[len++] = (int)(limit%10), limit /= 10;
  reverse(digits, digits+len);
  return dp(0, 0, 1, 1).y;
}

int main(){
  ios_base::sync_with_stdio(false);

  ll l, r;
  cin >> l >> r >> k;
  cout << sub(f(r), f(l-1)) << endl;

  return 0;
}