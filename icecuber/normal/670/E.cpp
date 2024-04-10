#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string seq;
  int n, m, p;
  cin >> n >> m >> p;
  p--;
  cin >> seq;

  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    l[i] = i-1;
    r[i] = i+1;
  }

  string cmd;
  cin >> cmd;
  for (char c : cmd) {
    if (c == 'R') {
      if (r[p] != n)
	p = r[p];
    } else if (c == 'L') {
      if (l[p] > -1)
	p = l[p];
    } else {
      assert(c == 'D');
      int p0 = p, a, b;
      if (seq[p] == '(') {
	int acc = 0;
	while (1) {
	  acc += (seq[p] == '(')*2-1;
	  if (!acc) break;
	  p = r[p];
	}
	a = p0, b = p;
      } else {
	int acc = 0;
	while (1) {
	  acc += (seq[p] == '(')*2-1;
	  if (!acc) break;
	  p = l[p];
	}
	a = p, b = p0;
      }
      if (l[a] != -1) r[l[a]] = r[b];
      if (r[b] != n) l[r[b]] = l[a];

      if (r[b] != n) p = r[b];
      else p = l[a];
    }
    //cout << c << ' ' << p << endl;
  }
  while (l[p] != -1) p = l[p];
  while (p != n) cout << seq[p], p = r[p];
  cout << endl;
}