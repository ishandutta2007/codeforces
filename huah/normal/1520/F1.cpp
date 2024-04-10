#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3fll
#define mp(x, y) make_pair(x, y)
void ast(ll x, ll l, ll r) { assert(x >= l && x <= r); }
const int N = 2e5 + 5;
int n, t;
int query(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}
int main() {
  scanf("%d%d", &n, &t);
  int k;scanf("%d",&k);
  int l=1,r=n;
  while(l<r)
  {
    int m=(l+r)>>1;
    if(m-query(1,m)>=k) r=m;
    else l=m+1;
  }
  printf("! %d\n",r);
  fflush(stdout);
}