#include <bits/stdc++.h>
using namespace std;

void succeed(pair<int, int> a, pair<int, int> b) {
  puts("YES");
  printf("%d %d %d %d\n", a.first+1, a.second+1, b.first+1, b.second+1);
  exit(0);
}

bool ok(pair<int, int> a, pair<int, int> b) {
  return a.first != b.first && a.first != b.second && a.second != b.first && a.second != b.second;
}

struct ans {
  pair<int, int> opt1, opt2, opt3;
  ans() : opt1({-1, -1}), opt2({-1, -1}), opt3({-1, -1}) {}
  void upd(pair<int, int> x) {
    if (opt1.first == -1) opt1 = x;
    else if (ok(opt1, x)) succeed(opt1, x);
    else if (opt2.first == -1) opt2 = x;
    else if (ok(opt2, x)) succeed(opt2, x);
    else if (opt3.first == -1) opt3 = x;
    else if (ok(opt3, x)) succeed(opt3, x);
  }
};

map<int, ans> hv;
int a[200005], n;

int main() {
  scanf("%d", &n);
  n = min(n, 5000);
  for (int i = 0; i < n; i++) scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++) {
      hv[a[i]+a[j]].upd({i, j});
    }
  puts("NO");
  return 0;
}