#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5 + 50;

int n, m, a[N], mx = 0;
priority_queue <int, vector <int>, greater <int> > Q;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &a[i]);
    mx = max(mx, a[i]);
    Q.push(a[i]);
  }
  for (int i = 1; i <= m; i ++) {
    int x = Q.top();
    Q.pop(); Q.push(x + 1);
  }
  int x = 0;
  while (Q.size()) {
    x = Q.top(); Q.pop();
  }
  printf("%d %d\n", x, mx + m);
  return 0;
}