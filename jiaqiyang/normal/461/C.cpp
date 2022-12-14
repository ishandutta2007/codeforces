#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

inline int low_bit(int x) { return x & -x; }

int n, l, r;
int tree[N], cnt[N];

inline void add(int pos, int val) {
  while (pos <= n) {
    tree[pos] += val;
    pos += low_bit(pos);
  }
}

inline int query(int pos) {
  int res = 0;
  while (pos) {
    res += tree[pos];
    pos -= low_bit(pos);
  }
  return res;
}

inline int get(int pos) { return query(pos) - query(pos - 1); }

bool flip = false;

inline void fold(int pos) {
  if (flip) pos = r - pos; else pos += l;
  if (pos - l < r - pos) {
    for (int i = 0; i < pos - l; ++i) add(pos + i + 1, get(pos - i));
    l = pos;
    flip = false;
  } else {
    for (int i = 0; i < r - pos; ++i) add(pos - i, get(pos + i + 1));
    r = pos;
    flip = true;
  }
}

inline int query(int a, int b) {
  if (flip) a = r - a, b = r - b, std::swap(a, b); else a += l, b += l;
  return query(b) - query(a);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n), l = 0, r = n;
  for (int i = 1; i <= n; ++i) add(i, cnt[i] = 1);
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    int op, a, b;
    scanf("%d%d", &op, &a);
    switch (op) {
      case 1:
        fold(a);
        break;
      case 2:
        scanf("%d", &b);
        printf("%d\n", query(a, b));
        break;
    }
  }
  return 0;
}