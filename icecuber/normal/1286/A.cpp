#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int inp[101];
int mem[101][101][101][2];
int f(int odds, int evens, int p, int last) {
  if (odds < 0 || evens < 0) return 1e9;
  if (p == 0) return 0;
  int&memo = mem[odds][evens][p][last];
  if (!memo) {
    int mi = 1e9;
    int v = inp[p-1];
    if (v == -1) {
      odds -= (last == 1);
      evens -= (last == 0);
      mi = min(f(odds, evens, p-1, last),
	       f(odds, evens, p-1, !last)+1);
    } else {
      if (last == v) {
	mi = min(f(odds, evens, p-1, last), f(odds, evens, p-1, !last)+1);
      }
    }
    memo = mi+1;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  set<int> left;
  for (int i = 0; i < n; i++) {
    left.insert(i);
    cin >> inp[i];
    inp[i]--;
  }
  for (int i = 0; i < n; i++) {
    if (inp[i] != -1) {
      left.erase(inp[i]);
      inp[i] = inp[i]%2;
    }
  }
  int odds = 0, evens = 0;
  for (int i : left) (i%2 ? odds : evens)++;
  cout << min(f(odds, evens, n, 0), f(odds, evens, n, 1)) << endl;
}