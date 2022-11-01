#include <bits/stdc++.h>
using namespace std;

#define D(x...) fprintf(stderr, x)

struct edge {
  int a, b, c;
};

vector<edge> edges;

void build_simple(int l, int r) {
  for (int i = 2; i < 32; i++) {
    edges.push_back({i, i+1, 1});
  }
  for (int i = l; i <= r; i++) {
    edges.push_back({1, 33-i, 1});
  }
}

void build_backbone() {
  for (int i = 0; i < 10; i++) {
    const int p = 1 << (2*(9-i));
    edges.push_back({3*i+2, 3*i+3, 1});
    edges.push_back({3*i+2, 3*i+4, 2*p+1});
    edges.push_back({3*i+2, 3*i+5, 1});
    edges.push_back({3*i+3, 3*i+4, p});
    edges.push_back({3*i+3, 3*i+5, p});
    edges.push_back({3*i+4, 3*i+5, p});
  }
  // We want to save node 2 for something special
  for (int i = 0; i < 3; i++) {
    edges.erase(edges.begin());
  }
}

void solve(int l, int r) {
  for (int i = 9; i >= 0; i--) {
    const int sz = r - l + 1;
    const int bits = (sz >> (2*i)) & 3;
    const int here = bits << (2*i);
    const int low = r - here + 1;
    D("segment: [%d, %d]\n", low, r);
    switch (bits) {
      case 2:
      case 3:
        edges.push_back({2, 33-3*i-bits, low-i});
        [[fallthrough]]
      case 1:
        edges.push_back({2, 32-3*i, low-i});
    }
    r -= here;
  }
}

int main() {
  int l, r;
  scanf("%d%d", &l, &r);
  if (r <= 31) {
    D("building simple\n");
    build_simple(l, r);
  } else {
    D("building backbone\n");
    build_backbone();
    if (l == 1) {
      edges.push_back({1, 32, 1});
      l += 1;
      D("special, l+=1: [%d, %d]\n", l, r);
    }
    if (l == 2) {
      edges.push_back({1, 29, 1});
      l += 4;
      D("special, l+=4: [%d, %d]\n", l, r);
    }
    if (l == 6) {
      edges.push_back({1, 26, 4});
      l += 16;
      D("special, l+=16: [%d, %d]\n", l, r);
    }
    l--;
    r--;
    edges.push_back({1, 2, 1});
    D("now solve: [%d, %d]\n", l, r);
    solve(l, r);
  }
  puts("YES");
  printf("%d %d\n", 32, (int)edges.size());
  for (const auto& u: edges) printf("%d %d %d\n", u.a, u.b, u.c);
  return 0;
}