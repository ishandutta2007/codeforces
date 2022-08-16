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

vi res;

void factor(int n) {
  for(int i = 2; i * i <= n; i++) if(n % i == 0) {
    int num = 1;
    while(n % i == 0) {
      n /= i;
      num *= i;
    }
    res.pb(num);
  }
  if(n > 1) {
    res.pb(n);
  }
}

int main() {
  int n;
  S(n);
  factor(n);

  if(res.size() < 2) {
    printf("NO\n");
    return 0;
  }
  int x = res.back();
  int y = 1;
  rep(i,0,res.size() - 1) {
    y *= res[i];
  }
  if(x < y) swap(x, y);
  printf("YES\n2\n");
  rep(i,1,y) {
    int rem = n - 1 - x * i;
    if(rem % y == 0) {
      printf("%d %d\n", rem / y, x);
      printf("%d %d\n", i, y);
      return 0;
    }
  }
  assert(0);
  return 0;
}