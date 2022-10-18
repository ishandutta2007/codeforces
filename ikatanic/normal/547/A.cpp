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
typedef pair<llint, llint> par;
#define x first
#define y second

const int MAX = 2e6;

int bio[MAX];

par solve(int h, int x, int y, int a, int m) {
  REP(i, m) bio[i] = -1;
  int t = 0;
  while (bio[h] == -1) {
    bio[h] = t++;
    h = (llint(h) * x + y) % m;
  }

  if (bio[a] == -1) return {-1, -1};
  if (bio[a] < bio[h]) return {0, bio[a]};
  return {t - bio[h], bio[a]};
}

par extended_euclid(llint a, llint b) {
  if (b == 0) return {1, 0};
  llint k = a / b;
  auto p = extended_euclid(b, a - k*b);
  return {p.y, p.x - k * p.y};
}

int main(void) {
  int m;
  scanf("%d", &m);
  
  int h1, a1, x1, y1, h2, a2, x2, y2;

  scanf("%d %d", &h1, &a1);
  scanf("%d %d", &x1, &y1);

  scanf("%d %d", &h2, &a2);
  scanf("%d %d", &x2, &y2);
  
  auto p1 = solve(h1, x1, y1, a1, m);
  auto p2 = solve(h2, x2, y2, a2, m);

  if (p1.x == -1 || p2.x == -1) {
    puts("-1");
    return 0;
  }
  
  if (p2.x == 0) swap(p1, p2);
  if (p1.x == 0) {
    if (p2.x == 0) printf("%lld\n", p1.y == p2.y ? p1.y : -1); else
      if (p1.y >= p2.y && p1.y%p2.x == p2.y%p2.x) printf("%lld\n", p1.y); else
        puts("-1");
    return 0;
  }
  
  llint A = p1.x;
  llint B = p2.x;
  llint C = p2.y - p1.y;
  llint G = __gcd(A, B);

  if (C % G) {
    puts("-1");
    return 0;
  }
  
  auto p = extended_euclid(A, B);
  p.x *= C/G, p.y *= C/G;

  llint lo = max(p1.y, p2.y);
  llint ans = p.x * p1.x + p1.y - lo;
  ans %= B/G*A;
  if (ans < 0) ans += B/G*A;
  ans += lo;

  printf("%lld\n", ans);
  return 0;
}