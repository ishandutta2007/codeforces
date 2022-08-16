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

int dp[201][201][4][4][5];
pii nxt[201][201][4][4][5];

int solve(int a, int b, int pa, int pb, int gn) {
  if(pa == 0 && pb == 0) {
    if(a || b) return 0;
    return 1;
  }

  int mx = (gn < 4) ? 25 : 15;
  int &res = dp[a][b][pa][pb][gn];
  if(res != -1) {
    return res;
  }
  res = 0;
  // process b first
  if((pb < pa && pb) || !pa) {
    rep(i,0,mx-1) {
      if(res) break;
      if(a >= i && b >= mx) {
        res |= solve(a - i, b - mx, pa, pb - 1, gn + 1);
        if(res) {
          nxt[a][b][pa][pb][gn] = mp(i, mx);
        }
      }
    }
    rep(i,mx+1,b+1) {
      if(res) break;
      if(a >= i - 2) {
        res |= solve(a - i + 2, b - i, pa, pb - 1, gn + 1);
        if(res) {
          nxt[a][b][pa][pb][gn] = mp(i - 2, i);
        }
      }
    }
  } else {
    rep(i,0,mx-1) {
      if(res) break;
      if(b >= i && a >= mx) {
        res |= solve(a - mx, b - i, pa - 1, pb, gn + 1);
        if(res) {
          nxt[a][b][pa][pb][gn] = mp(mx, i);
        }
      }
    }
    rep(i,mx+1,a+1) {
      if(res) break;
      if(b >= i - 2) {
        res |= solve(a - i, b - i + 2, pa - 1, pb, gn + 1);
        if(res) {
          nxt[a][b][pa][pb][gn] = mp(i, i - 2);
        }
      }
    }
  }
  return res;
}

void gen(int a, int b, int pa, int pb, int gn) {
  if(pa == 0 && pb == 0) return;
  pii p = nxt[a][b][pa][pb][gn];
  printf("%d:%d ",p.FF,p.SS);
  gen(a - p.FF, b - p.SS, pa - (p.FF > p.SS), pb - (p.SS > p.FF), gn + 1);
}

int main() {
  memset(dp, -1, sizeof(dp));
  int t;
  S(t);
  while(t--) {
    int a,b;
    S2(a,b);
    int pa = -1, pb = -1;
    bool ok = false;

    if(!ok && solve(a, b, 3, 0, 0)) pa = 3, pb = 0, ok = true;
    if(!ok && solve(a, b, 3, 1, 0)) pa = 3, pb = 1, ok = true;
    if(!ok && solve(a, b, 3, 2, 0)) pa = 3, pb = 2, ok = true;
    if(!ok && solve(a, b, 2, 3, 0)) pa = 2, pb = 3, ok = true;
    if(!ok && solve(a, b, 1, 3, 0)) pa = 1, pb = 3, ok = true;
    if(!ok && solve(a, b, 0, 3, 0)) pa = 0, pb = 3, ok = true;

    if(ok) {
      printf("%d:%d\n",pa,pb);
      gen(a, b, pa, pb, 0);
      printf("\n");
    } else {
      printf("Impossible\n");
    }
  }
  return 0;
}