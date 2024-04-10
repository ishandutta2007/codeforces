#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll niz[MAXN];

ll a1[MAXN];
ll a2[MAXN];

int x[MAXN], y[MAXN], d[MAXN];

int main() {
   int n, m, k;
   cin >> n >> m >> k;

   for(int i = 0; i < n; ++i)
      cin >> niz[i];

   for(int i = 0; i < m; ++i)
      cin >> x[i] >> y[i] >> d[i];

   for(int i = 0; i < k; ++i) {
      int a, b; cin >> a >> b;
      a1[a - 1] ++;
      a1[b] --;
   }

   int open = 0;

   for(int i = 0; i < m; ++i) {
      open += a1[i];
      a2[x[i] - 1] += (ll)d[i] * open;
      a2[y[i]] -= (ll)d[i] * open;
   }

   ll tmp = 0;

   for(int i = 0; i < n; ++i) {
      tmp += a2[i];
      cout << niz[i] + tmp << " ";
   }
}