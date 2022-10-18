#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  vector<pair<int, int>> v;
  REP(i, n) {
    scanf("%d", &a[i]);
    v.push_back({a[i], i});
  }

  sort(v.begin(), v.end());

  vector<int> ans(n);
  ans[n-1] = v.back().first;

  int kEven = n - 2;
  int kOdd = n - 3;
  
  int closest1a = -1;
  int closest2a = -1;
  int closest1b = -1;
  int closest2b = -1;
  int mid = (n - 1) / 2;

  auto canWin = [&] (int k) {
    if ((n - k) % 2 == 1) {
      for (int closest2 : {closest2a, closest2b}) {
        if (closest2 != -1) {
          int L = closest2;
          int R = n - closest2 - 1;
          if (max(L, R) - min(L, R) <= k) return true;
          L = closest2 + 1;
          R = n - (closest2 + 1) - 1;
          if (max(L, R) - min(L, R) <= k) return true;
        }
      }
      return false;
    } else {
      for (int closest1 : {closest1a, closest1b}) {
        if (closest1 != -1) {
          int L = closest1;
          int R = n - closest1 - 1;
          if (max(L, R) - min(L, R) - 1 <= k) return true;
        }
      }
      return false;
    }
  };
  
  for (int i = n-1; i >= 0; --i) {
    int x = v[i].first;
    int j = v[i].second;
    if (j <= mid) {
      if (closest1a == -1 || mid - j < mid - closest1a) closest1a = j;
      if (j + 1 < n && a[j + 1] > x) {
        if (closest2a == -1 || mid - j < mid - closest2a) closest2a = j;
      }
    } else {
      if (closest1b == -1 || j - mid < closest1b - mid) closest1b = j;
      if (j + 1 < n && a[j + 1] > x) {
        if (closest2b == -1 || j - mid < closest2b - mid) closest2b = j;
      }
    }

    if (j-1 <= mid) {
      if (j - 1 >= 0 && a[j - 1] >= x) {
        if (closest2a == -1 || mid - (j - 1) < mid - closest2a) closest2a = j - 1;
      }
    } else {
      if (j - 1 >= 0 && a[j - 1] >= x) {
        if (closest2b == -1 || j-1 - mid < closest2b - mid) closest2b = j - 1;
      }
    }
    
    while (kEven >= 0 && canWin(kEven)) {
      ans[kEven] = v[i].first;
      kEven -= 2;
    }
    while (kOdd >= 0 && canWin(kOdd)) {
      ans[kOdd] = v[i].first;
      kOdd -= 2;
    }
  }
  
  REP(i, n) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}