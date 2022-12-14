#include <cstdio>
#include <set>

typedef long long i64;

int w, h, n;

void maintain(std::set<int> &s, std::multiset<int> &d, int p) {
  std::set<int>::iterator it = s.insert(p).first, succ = it, pred = it;
  --pred;
  ++succ;
  d.erase(d.find(*succ - *pred));
  d.insert(p - *pred);
  d.insert(*succ - p);
  s.insert(p);
}

int main() {
  scanf("%d%d%d", &w, &h, &n);
  std::set<int> x, y;
  std::multiset<int> dx, dy;
  x.insert(0);
  x.insert(w);
  y.insert(0);
  y.insert(h);
  dx.insert(w);
  dy.insert(h);
  while (n--) {
    char op;
    int t;
    scanf(" %c%d", &op, &t);
    if (op == 'H') {
      maintain(y, dy, t);
    } else {
      maintain(x, dx, t);
    }
    printf("%I64d\n", (i64)*dx.rbegin() * *dy.rbegin());
  }
  return 0;
}