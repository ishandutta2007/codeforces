#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int i, j, n, m, a[N], k[N], freq[N], rs = -1, sm, cnt, toDelete;

void add(int x) {
  ++freq[x];
  if(freq[x] == k[x]) ++cnt;
  if(freq[x] > k[x]) ++toDelete;
}

void del(int x) {
  --freq[x];
  if(freq[x] == k[x] - 1) --cnt;
  if(freq[x] >= k[x]) --toDelete;
}

int main() {
  scanf("%d %d", &n, &m);
  for(i = 1; i <= n; ++i) scanf("%d", a + i);
  for(i = 1; i <= m; ++i) scanf("%d", k + i), sm += k[i], cnt += (k[i] == 0);

  for(j = i = 1; i <= n; ++i) {
    add(a[i]);
    while(j <= i && freq[a[j]] > k[a[j]]) del(a[j]), ++j;
    if(cnt == m && rs == -1) rs = toDelete;
    if(cnt == m) rs = min(rs, toDelete);
  }

  printf("%d\n", rs);

  return 0;
}