#include <bits/stdc++.h>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;
char buf[1000];

vector<int> tst;

bool gans(int x, int y) {
  printf("1 %d %d\n", x, y);
  fflush(stdout);

#ifdef DEBUG
  int r = 1e9,s = 1e9;
  for (int t : tst) {
    r = min(r, abs(x-t));
    s = min(s, abs(y-t));
  }
  return r <= s;
#endif

  scanf(" %s", buf);
  return buf[0] == 'T';
}

int main() {
  scanf("%d %d", &n, &k);
#ifdef DEBUG
  tst.resize(k);
  FO(i,0,k) scanf("%d", &tst[i]);
#endif

  int l = 1, r = n;
  while (l < r) {
    int md = (l+r)/2;
    if (gans(md,md+1)) {
      r = md;
    } else {
      l = md+1;
    }
  }
  int d0 = l;

  l = 1; r = d0;
  while (l < r) {
    int md = (l+r-1)/2;
    if (gans(md,md+1)) {
      r = md;
    } else {
      l = md+1;
    }
  }

  if (l != d0) {
    printf("2 %d %d\n", l, d0);
    fflush(stdout);
    return 0;
  }

  l = d0; r = n;
  while (l < r) {
    int md = (l+r)/2;
    if (gans(md+1,md)) {
      l = md+1;
    } else {
      r = md;
    }
  }

  if (l != d0) {
    printf("2 %d %d\n", l, d0);
    fflush(stdout);
    return 0;
  }

  assert(false);
}