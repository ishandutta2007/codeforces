#include <cctype>
#include <cstdio>
#include <set>
#include <vector>

typedef std::pair<int, int> Info;

const int N = 300000 + 10;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, q;

std::set<Info> pool;

void erase(int x) {
  for (std::set<Info>::iterator it = pool.lower_bound(Info(x, 0)); it != pool.end() && it->first == x;) pool.erase(it++);
}

int main() {
  scanf("%d%d", &n, &q);
  std::vector<int> x;
  for (int cur = 0; q--;) {
    int op = nextInt();
    if (op == 1) {
      int t = nextInt();
      pool.insert(Info(t, x.size()));
      x.push_back(t);
    } else if (op == 2) {
      erase(nextInt());
    } else {
      int t = nextInt();
      for (; cur < t; ++cur) pool.erase(Info(x[cur], cur));
    }
    printf("%d\n", pool.size());
  }
  return 0;
}