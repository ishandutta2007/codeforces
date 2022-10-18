#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;

int a[MAXN];
llint fl[MAXN], fr[MAXN];
llint gl[MAXN], gr[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);

  fl[0] = gl[0] = 0;
  for (int i = 1; i <= n; ++i) {
    fl[i] = 0;
    if (a[i] > 1) fl[i] = fl[i-1] + (a[i]/2)*2;
    gl[i] = max(fl[i-1], gl[i-1]);
    if (a[i]%2 == 0) gl[i] += a[i]-1; else
      gl[i] += a[i];
  }
  fr[n] = gr[n] = 0;
  for (int i = n-1; i >= 0; --i) {
    fr[i] = 0;
    if (a[i+1] > 1) fr[i] = fr[i+1] + (a[i+1]/2)*2;
    gr[i] = max(fr[i+1], gr[i+1]);
    if (a[i+1]%2 == 0) gr[i] += a[i+1]-1; else
      gr[i] += a[i+1];
  }

  llint ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = max(ans, fl[i] + gr[i]);
    ans = max(ans, gl[i] + fr[i]);
    ans = max(ans, fl[i] + fr[i]);
  }
  cout << ans << endl;
  return 0;
}