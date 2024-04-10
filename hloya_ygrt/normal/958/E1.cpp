#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int xa[N];
int xb[N];
int ya[N];
int yb[N];

struct pt {
  int x, y;

  pt(int x, int y): x(x), y(y) {
  }
};

inline int area (pt a, pt b, pt c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
inline bool intersect_1 (int a, int b, int c, int d) {
  if (a > b)  swap (a, b);
  if (c > d)  swap (c, d);
  return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d) {
  return intersect_1 (a.x, b.x, c.x, d.x)
    && intersect_1 (a.y, b.y, c.y, d.y)
    && area(a,b,c) * area(a,b,d) <= 0
    && area(c,d,a) * area(c,d,b) <= 0;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  if (n != m) {
    puts("No");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", xa + i, ya + i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", xb + i, yb + i);
  }
  vector<int> id(n);
  for (int i = 0; i < n; i++) {
    id[i] = i;
  }
  do {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        pt a = pt(xa[i], ya[i]);
        pt b = pt(xb[id[i]], yb[id[i]]);
        pt c = pt(xa[j], ya[j]);
        pt d = pt(xb[id[j]], yb[id[j]]);
        if (intersect(a, b, c, d)) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      puts("Yes");
      return 0;
    }
  } while (next_permutation(id.begin(), id.end()));
  puts("No");
  return 0;  
}