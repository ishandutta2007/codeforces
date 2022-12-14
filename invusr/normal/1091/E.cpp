#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

template <class T>
bool relax(T &a, T b) {
  return b > a ? a = b, true : false;
}
template <class T>
bool tense(T &a, T b) {
  return b < a ? a = b, true : false;
}

int getint() {
  char c;
  while ((c = getchar()) < '0' || c > '9');

  int result = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') {
    result = result * 10 + c - '0';
  }
  return result;
}

const int N = 555555;
const int M = N << 2;

int n;
int a[N];

int m = 0;
int b[N / 2];

int c[N];

int sa[M], sb[M], da[M];

void add(int x, int d) {
  sa[x] += d;
  sb[x] += d;
  da[x] += d;
}
void pull(int x) {
  if (da[x]) {
    add(x << 1, da[x]);
    add(x << 1 | 1, da[x]);
    da[x] = 0;
  }
}
void push(int x) {
  sa[x] = sa[x << 1];
  sb[x] = sb[x << 1 | 1];
}

void build(int x, int l, int r) {
  da[x] = 0;
  if (l == r) {
    sa[x] = sb[x] = c[l];
  } else {
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    push(x);
  }
}
void add(int x, int l, int r, int p, int q, int d) {
  if (l == p && r == q) {
    add(x, d);
    return;
  }
  pull(x);
  int mid = l + r >> 1;
  if (q <= mid) {
    add(x << 1, l, mid, p, q, d);
  } else {
    if (p > mid) {
      add(x << 1 | 1, mid + 1, r, p, q, d);
    } else {
      add(x << 1, l, mid, p, mid, d);
      add(x << 1 | 1, mid + 1, r, mid + 1, q, d);
    }
  }
  push(x);
}
int queryr(int v) {
  int l = 1, r = n + 1, x = 1;
  while (l < r) {
    pull(x);
    int mid = l + r >> 1;
    if (sa[x << 1 | 1] < v) {
      x <<= 1;
      r = mid;
    } else {
      x = x << 1 | 1;
      l = mid + 1;
    }
  }
  return l;
}
int queryl(int v) {
  int l = 1, r = n + 1, x = 1;
  while (l < r) {
    pull(x);
    int mid = l + r >> 1;
    if (sb[x << 1] <= v) {
      x <<= 1;
      r = mid;
    } else {
      x = x << 1 | 1;
      l = mid + 1;
    }
  }
  return l;
}
int find(int p) {
  int x = 1, l = 1, r = n + 1;
  while (l < r) {
    pull(x);
    int mid = l + r >> 1;
    if (p <= mid) {
      x <<= 1;
      r = mid;
    } else {
      x = x << 1 | 1;
      l = mid + 1;
    }
  }
  return sa[x];
}
void test(int x, int l, int r) {
  if (l == r) {
    cout << sa[x] << (l == n + 1 ? '\n' : ' ');
  } else {
    pull(x);
    int mid = l + r >> 1;
    test(x << 1, l, mid);
    test(x << 1 | 1, mid + 1, r);
  }
}

s64 sm[N];

int check(int vv) {
  int dd = 0;
  for (int i = n; i; --i) {
    if (vv <= a[i]) {
      dd = i;
      break;
    }
  }
  int kk = 0;
  for (int i = 1; i <= dd; ++i) {
    c[++kk] = a[i];
  }
  c[++kk] = vv;
  for (int i = dd + 1; i <= n; ++i) {
    c[++kk] = a[i];
  }

  build(1, 1, n + 1);
  int id = queryl(vv);
//  test(1, 1, n + 1);

  sm[0] = 0;
  for (int i = 1; i <= n + 1; ++i) {
    sm[i] = sm[i - 1] + c[i];
  }
  for (int i = 1; i <= n; ++i) {
    int l = i + 1, r = n + 1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (c[mid] > i) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    s64 ww = (r - i) * (s64)i + sm[n + 1] - sm[r];
    if (sm[i] > (s64)i * (i - 1) + ww) {
      return i < id ? -1 : 1;
    }
  }

  return 0;
}

int main() {
  cin >> n;
  s64 sum = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = getint();
    sum += a[i];
  }
  sort(a + 1, a + n + 1, greater<int>());

  for (int i = sum & 1; i <= n; i += 2) {
    b[++m] = i;
 //   cout << i << ' ' << check(i) << endl;
  }

  int vl = 1, vr = m;
  while (vl <= vr) {
    int mid = vl + vr >> 1;
    if (check(b[mid]) >= 0) {
      vr = mid - 1;
    } else {
      vl = mid + 1;
    }
  }
  int l = vl;
  if (check(b[vl])) {
    puts("-1");
    return 0;
  }

  vl = l, vr = m;
  while (vl <= vr) {
    int mid = vl + vr >> 1;
    if (!check(b[mid])) {
      vl = mid + 1;
    } else {
      vr = mid - 1;
    }
  }
  int r = vr;

  for (int i = l; i <= r; ++i) {
    printf("%d ", b[i]);
  }

  return 0;
}