#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1010;

int w[MAXN], h[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", w+i, h+i);
  
  int sumw = accumulate(w, w + n, 0);
  int maxh = *max_element(h, h + n);
  int ans = sumw * maxh;
  
  for (int H = 1; H <= 1000; ++H) {
    int cnt = 0;
    static vector<int> v; v.clear();

    int sumw = 0;
    REP(i, n)
      if (h[i] > H) {
        if (w[i] > H) { cnt = n; break; }
        cnt++;
        sumw += h[i];
      } else {
        sumw += w[i];
        if (w[i] <= H) v.push_back(w[i] - h[i]);
      }
    
    if (cnt*2 > n) continue;

    sort(v.begin(), v.end());
    while ((cnt+1)*2 <= n && (int)v.size() && v.back() > 0) {
      sumw -= v.back();
      v.pop_back();
      cnt++;
    }

    ans = min(ans, sumw * H);
  }
  
  printf("%d\n", ans);
  return 0;
}