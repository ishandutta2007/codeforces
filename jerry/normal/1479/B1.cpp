#include <bits/stdc++.h>
using namespace std;

queue<int> occ[100005];
vector<int> a, b;
int x[100005];
int n, ans;

void a_(int v) {
  if (a.empty() || a.back() != v) ans++;
  a.push_back(v);
}

void b_(int v) {
  if (b.empty() || b.back() != v) ans++;
  b.push_back(v);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", x+i);
    occ[x[i]].push(i);
  }
  for (int i = 0; i <= n; i++) occ[i].push(n+5);
  a.push_back(0); b.push_back(0);
  for (int i = 0; i < n; i++) {
    occ[x[i]].pop();
    if (x[i] == a.back()) b_(x[i]);
    else if (x[i] == b.back()) a_(x[i]);
    else if (occ[a.back()].front() > occ[b.back()].front()) b_(x[i]);
    else a_(x[i]);
  }
  printf("%d\n", ans);
  return 0;
}