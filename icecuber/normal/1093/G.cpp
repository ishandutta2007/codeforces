#include <bits/stdc++.h>
using namespace std;

const int nax = 1<<18;
struct Tree {
  int mi[nax*2], ma[nax*2];
  Tree() {
    fill_n(mi, nax*2, 1e9);
    fill_n(ma, nax*2,-1e9);
  }
  void set(int i, int v) {
    i += nax;
    mi[i] = ma[i] = v;
    for (i /= 2; i; i /= 2) {
      mi[i] = min(mi[i*2], mi[i*2+1]);
      ma[i] = max(ma[i*2], ma[i*2+1]);
    }
  }
  int query(int l, int r) {
    l += nax, r += nax;
    int qmi = mi[l], qma = ma[l];
    for (; r-l > 1; l/=2, r/=2) {
      if (l%2==0) {
	qmi = min(qmi, mi[l+1]);
	qma = max(qma, ma[l+1]);
      }
      if (r%2) {
	qmi = min(qmi, mi[r-1]);
	qma = max(qma, ma[r-1]);
      }
    }
    return qma-qmi;
  }
} tree[16];

int k;
void setpoint(int i) {
  int a[5];
  for (int l = 0; l < k; l++)
    cin >> a[l];
  for (int j = 0; j < 1<<k-1; j++) {
    int sum = a[k-1];
    for (int l = 0; l < k-1; l++)
      sum += (j>>l&1 ? 1:-1)*a[l];
    tree[j].set(i, sum);
  }
}

int main() {
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) setpoint(i);
  int q;
  cin >> q;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i;
      cin >> i;
      i--;
      setpoint(i);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      int ans = 0;
      for (int j = 0; j < 1<<k-1; j++)
	ans = max(ans, tree[j].query(l, r));
      cout << ans << endl;
    }
  }
}