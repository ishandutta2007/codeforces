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

int mask(string& x) {
  int mas = 0;
  for(int i=0; i<SZ(x); i++) {
    mas <<= 1;
    if(x[i] == '1') mas ^= 1;
  }
  return mas;
}

int M[1<<12];
int res[1<<12][107];

int main() {
  int n, q, m;
  scanf("%d%d%d", &n, &q, &m);
  vector <ll> ans(m);
  vi w(n);
  for(int i=0; i<n; i++) cin >> w[i];
  reverse(ALL(w));
  for(int i=0; i<q; i++) {
    char a[15];
    scanf("%s", a);
    string sa = string(a);
    M[mask(sa)]++;
  }
  for(int i=0; i<(1<<n); i++) {
    vector <pair <ll, int> > X;
    for(int j=0; j<(1<<n); j++) {
      int diff = ~(i ^ j);
      int ret = 0;
      for(int k=0; k<n; k++) {
        if(diff & (1<<k)) ret += w[k];
      }
      if(ret <= 100) res[i][ret] += M[j];
    }
    for(int j=1; j<=100; j++) res[i][j] += res[i][j-1];
  }
  for(int i=0; i<m; i++) {
    char b[15];
    int c;
    scanf("%s%d", b, &c);
    string sb = string(b);
    printf("%d\n", res[mask(sb)][c]);
  }
  return 0;
}