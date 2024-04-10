#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, k, m, t;
int q[N * 2];

int get_pos() {
  for (int i = 1; i <= n; i++) {
    if (q[i]) return i;
  } 
  return 0;
}

int main() {
  scanf("%d %d %d %d", &n, &k, &m, &t);
  q[k] = 1;
  while (t--) {
    int op, x;
    scanf("%d %d", &op, &x);
    if (op == 1) {
      for (int i = n; i >= x; i--) q[i + 1] = q[i];
      q[x] = 0;
      ++n;
    } else {
      int cur = get_pos();
      // cout << cur << " " << x << "+" << endl;
      if (cur > x) {
        for (int i = x + 1; i <= n; i++) {
          q[i - x] = q[i];
        }
        n -= x;
        // cout << "+" << x << " " << n << endl;
      } else {
        n = x;
      }
    }
    cout << n << " " << get_pos() << endl;
  }

  return 0;
}