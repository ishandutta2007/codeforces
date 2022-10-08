//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 15000000;
int dzi[MAXN+7], zlicz[MAXN+7];

void sito(int n) {
  for(int i=2; i*i<=n; i++) {
    if(dzi[i] == 0) {
      for(int j=i*i; j<=n; j+=i) dzi[j] = i;
    }
  }
  for(int i=2; i<=n; i++) if(dzi[i] == 0) dzi[i] = i;
}

void foo(int v) {
  if(v == 1) return;
  int d = dzi[v];
  zlicz[d]++;
  while(v % d  == 0) v /= d;
  foo(v);
}

int main() {
  ios_base::sync_with_stdio(0);
  sito(MAXN);
  int n;
  cin >> n;
  vector <int> A(n);
  int gcd = 0;
  for(int i=0; i<n; i++) {
    cin >> A[i];
    gcd = __gcd(gcd, A[i]);
  }
  for(int i=0; i<n; i++) A[i] /= gcd;
  for(int i=0; i<n; i++) foo(A[i]);
  int res = 0;
  for(int i=2; i<=MAXN; i++) {
    res = max(res, zlicz[i]);
  }
  if(res != 0) res = n - res;
  else res = -1;
  cout << res << "\n";
  return 0;
}