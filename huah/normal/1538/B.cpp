#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int n, a[N], mn, mx;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll sum=0;for(int i=1;i<=n;i++) sum+=a[i];if(sum%n) {printf("-1\n");continue;}else{int ans=0;for(int i=1;i<=n;i++) if(a[i]>sum/n) ans++;printf("%d\n",ans);}
  }
}