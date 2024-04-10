#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

const int MOD = (int)1e9 + 7;

const int N = 2e6 + 5;

int fact[N];
int ifact[N];

int pw(int a, int p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) res = (int)(1LL * res * a % MOD);
    a = (int)(1LL * a * a % MOD);
    p >>= 1;
  }
  return res;
}

int inv(int a) {
  return a == 1 ? 1 : (long long)(MOD - MOD / a) * inv(MOD % a) % MOD;
}

void pre() {
  fact[0] = 1;
  ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (int)(1LL * fact[i - 1] * i % MOD);
    ifact[i] = (int)(1LL * ifact[i - 1] * inv(i) % MOD);
  }
}

int f(int n) {
  int res = fact[2 * n - 1];
  res = res * 2 % MOD;
  res = (int)(1LL * res * ifact[n] % MOD);
  res = (int)(1LL * res * ifact[n - 1] % MOD);
  res += MOD - 1;
  res %= MOD;
  return res;
}

int main() {
  pre();
  int n;
  cin >> n;
  cout << f(n + 1) << endl;
  return 0;
}