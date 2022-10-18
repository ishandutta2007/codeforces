#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 300300;

struct Loga {
  int L[MAXN];
  
  void add(int x, int y) {
    for (++x; x < MAXN; x += x&-x)
      L[x] += y;
  }

  int sum(int x) {
    int ans = 0;
    for (++x; x; x -= x&-x)
      ans += L[x];
    return ans;
  }

  int sum(int x, int y) {
    return sum(y) - sum(x-1);
  }
} L;

vector<int> E[MAXN];
int a[MAXN], b[MAXN];
int c[MAXN];

void add(int x, int d) {
  L.add(c[x], -1);
  c[x] += d;
  L.add(c[x], +1);
}

int main(void) {
  int n, p;
  scanf("%d %d", &n, &p);

  L.add(0, +n);

  REP(i, n) {
    scanf("%d %d", a+i, b+i);
    --a[i], --b[i];
    E[a[i]].push_back(i);
    E[b[i]].push_back(i);
    add(a[i], +1), add(b[i], +1);
  }

  llint ans = 0;
  REP(i, n) {
    for (int j: E[i])
      if (a[j] == i) add(b[j], -1); else
        add(a[j], -1);
    L.add(c[i], -1);

    int cnt = E[i].size();
    ans += L.sum(max(0, p-cnt), n);
    
    for (int j: E[i])
      if (a[j] == i) add(b[j], +1); else
        add(a[j], +1);
    L.add(c[i], +1);
  }

  ans /= 2;
  cout << ans << endl;
  return 0;
}