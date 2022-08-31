#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const LL INF = 1e18;

LL f(int n, int a, int b, int k) {
  LL res = ((n + 1) >> 1) * 1LL * a;
  res += (n >> 1) * 1LL * b;
  return res / k;
}

LL g(int n, int a, int k) {
  if(!k) return INF;
  return (n * 1LL * a) / k;
}

int main() {
  int t,n,a,b,k;
  scanf("%d%d%d%d%d",&t,&n,&a,&b,&k);
  if(k > n) {
    P(0);
    return 0;
  } else if(n >= 2 * k) {
    printf("%lld\n",min(f(n,a,b,k), t * 1LL));
  } else {
    LL v1 = a;
    LL v2 = g((n + 0) >> 1, b, k - ((n + 1) >> 1));

    if(v2 <= v1) {
      printf("%lld\n",min(v2, t * 1LL));
      return 0;
    }

    v1 = b;
    v2 = g((n + 1) >> 1, a, k - ((n + 0) >> 1));

    if(v2 <= v1) {
      printf("%lld\n",min(v2, t * 1LL));
      return 0;
    }

    printf("%lld\n",min(f(n,a,b,k), t * 1LL));
  }
  return 0;
}