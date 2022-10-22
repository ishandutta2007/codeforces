#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> child[nax];

int s[nax], e[nax];
int t = 0;
void dfs(int p) {
  s[p] = t++;
  for (int i : child[p]) {
    dfs(i);
  }
  e[p] = t;
}

const int n = 1<<18;
int off[n*2], sum[n*2];

void push(int i, int w) {
  if (off[i]) {
    sum[i] = w-sum[i];
    if (i < n) {
      off[i*2] ^= 1;
      off[i*2+1] ^= 1;
    }
    off[i] = 0;
  }
}

void flip(int a, int b, int l = 0, int r = n, int i = 1) {
  assert(i < n*2);
  push(i, r-l);
  if (a <= l && b >= r) {
    off[i] ^= 1;
  push(i, r-l);
  } else if (a >= r || b <= l) return;
  else {
    push(i, r-l);
    int m = l+r>>1;
    flip(a, b, l, m, i*2);
    flip(a, b, m, r, i*2+1);
    sum[i] = sum[i*2]+sum[i*2+1];
  }
}

int query(int a, int b, int l = 0, int r = n, int i = 1) {
  assert(i < n*2);
  push(i, r-l);
  if (a <= l && b >= r) {
    return sum[i];
  } else if (a >= r || b <= l) return 0;
  else {
    int m = l+r>>1;
    return query(a, b, l, m, i*2) + query(a, b, m, r, i*2+1);
  }
}

/*void flip(int r) {
  int w = 1;
  for (int i = r+n; i > 1; i >>= 1) {
    if (i&1) {
      off[i-1] ^= 1;
    }
    int a = off[i] ? w-sum[i] : sum[i];
    int b = off[i^1] ? w-sum[i^1] : sum[i^1];
    sum[i>>1] = a + b;
    w *= 2;
  }
}

int query(int r) {
  int ans = 0, w = 1;
  for (int i = r+n; i > 1; i >>= 1) {
    if (i&1) {
      ans += sum[i-1];
    }
    if (off[i]) ans = w-ans;
    w *= 2;
  }
  return ans;
}
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    child[p].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t) flip(s[i], s[i]+1);
  }
  int q;
  cin >> q;
  while (q--) {
    string cmd;
    cin >> cmd;
    if (cmd == "pow") {
      int p;
      cin >> p;
      p--;
      flip(s[p], e[p]);
    } else {
      assert(cmd == "get");
      int p;
      cin >> p;
      p--;
      cout << query(s[p], e[p]) << endl;
    }
  }
}