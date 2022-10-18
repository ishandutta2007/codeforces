#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

using i64 = int64_t;

struct Op {
  i64 a, b, op;
};

vector<Op> ret;

void go(i64 x) {
  auto make = [&](i64 x, i64 y) {
    if (y == 0) return;
    assert(y > 0);

    i64 r = x;
    y--;
    while (y > 0) {
      if (y % 2) {
        ret.push_back({r, x, 0});
        r += x;
      }
      y /= 2;
      ret.push_back({x, x, 0});
      x *= 2;
    }
  };

  i64 c = 1;
  while (((x * c) ^ x) % 2 == 1 || __gcd(x, (x * c) ^ x) != 1) c++;

  make(x, c);
  ret.push_back({x * c, x, 1});

  i64 y = (x * c) ^ x;

  i64 a = 1;
  while ((a * y + 1) % x) {
    a++;
  }

  make(y, a);
  make(x, (a * y + 1) / x);
  ret.push_back({a * y, a * y + 1, 1});
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  go(n);

  cout << ret.size() << '\n';
  for (auto& o : ret) {
    cout << o.a << ' ' << (o.op ? '^' : '+') << ' ' << o.b << '\n';
  }
  return 0;
}