#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

constexpr int maxn = 7005;

bitset<maxn> a[101 * 1000];
bitset<maxn> cn[maxn];
bitset<maxn> mn[maxn];
//vi divs[maxn];

void out(int it, bitset<maxn>& a) {
  cerr << it << ": ";
  for (int i = 0; i < maxn; ++i)
    if (a[i]) cerr << i << " ";
  cerr <<"\n";
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vi mu;
  for (int i = 1; i < maxn;++i ){
    bool ok = true;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0 && (i / j) % j == 0) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    //cerr << i << " ";
    mu.pb(i);
  }
  for (int i = 1; i < maxn; ++i) {
    for (int x : mu) {
      if (i * x >= maxn) continue;
      mn[i][i * x] = true;
    }
  }
  //cerr << sz(mu) << "\n";
  for (int i = 1; i < maxn; ++i) {
    //for (int j = i; j < maxn; j += i)
    //  cn[i][j] = true;
    for (int j = 1; j <= i; ++j)
      if (i % j == 0) {
        cn[i][j] = true;
        //bool ok = true;
        //for (int t = 2; t * t <= j; ++t) {
        //  if (j % t == 0 && (j / t) % t == 0) {
        //    ok = false;
        //    break;
        //  }
        //}
        //if (ok) divs[i].pb(j);
      }
  }
  for (int i = 0; i < q; ++i) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int ind, x;
      scanf("%d%d", &ind, &x);
      a[ind] = cn[x];
      //out(i, a[ind]);
      continue;
    }
    if (ty == 2) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      a[x] = a[y] ^ a[z];
      //out(i, a[x]);
      continue;
    }
    if (ty == 3) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      a[x] = a[y] & a[z];
      //out(i, a[x]);
      continue;
    }
    int ind, x;
    scanf("%d%d", &ind, &x);
    //out(i, a[ind]);
    //int res = 0;
    //for (int y : mu) {
    //  if (x * y >= maxn) break;
    //  //cerr << y << " " << a[ind][x / y] << "; ";
    //  res += a[ind][x * y] ? 1 : 0;
    //}
    //res %= 2;
    int res = (a[ind] & mn[x]).count() % 2;
    printf("%d", res);
  }
  printf("\n");
  return 0;
}