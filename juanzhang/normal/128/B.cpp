#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, k;
string str;

struct node {
  string s; int pos;

  inline bool operator < (const node &o) const {
    return s > o.s;
  }
};

priority_queue <node> Q;

int main() {
  cin >> str >> k;
  n = str.size();
  if (k > 1ll * n * (n + 1) / 2) {
    return puts("No such line."), 0;
  }
  node tmp;
  for (int i = 0; i < n; i++) {
    tmp.s = "", tmp.s += str[i];
    tmp.pos = i + 1;
    Q.push(tmp);
  }
  while (1) {
    tmp = Q.top();
    if (!--k) {
      cout << tmp.s; return 0;
    }
    Q.pop();
    if (tmp.pos < n) {
      tmp.s += str[tmp.pos++], Q.push(tmp);
    }
  }
  return 0;
}