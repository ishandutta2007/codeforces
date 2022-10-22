#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5, mod = 1e9 + 9;

int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}
int pot(int x, int e) {
  if(e == 0) return 1;
  int ret = x; e --;
  while(e) {
    if(e % 2) ret = mul(ret, x);
    x = mul(x, x);
    e /= 2;
  }

  return ret;
}

string s;

int ia, ib;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, a, b, k; cin >> n >> a >> b >> k;

  ia = pot(a, mod - 2);
  ib = pot(b, mod - 2);

  cin >> s;

  int A = pot(a, n);
  int B = 1;

  int first = 0;

  REP(i, k) {
    int ml = -1;
    if(s[i] == '+') ml = 1;

    ml += mod;
    ml %= mod;

    first = add(first, mul(ml, mul(A, B)));
    A = mul(A, ia);
    B = mul(B, b);
  }

  int q = mul(pot(ia, k), pot(b, k));
  int N = (n + 1) / k;

  if(q == 1) {
    cout << mul(first, N);
  }
  else {
    cout << mul(mul(first, sub(1, pot(q, N))), pot(sub(1, q), mod - 2));
  }
}