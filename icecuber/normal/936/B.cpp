#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
int mem[nax][2];

vector<int> path;
int f(int p, int t) {
  if (mem[p][t]) return mem[p][t]-2;
  mem[p][t] = 2;

  if (node[p].empty()) {
    if (t == 0) {
      mem[p][t] = 1;
      return -1;
    }
    else {
      path.push_back(p);
      return 1;
    }
  }
  int r = -1;
  for (int i : node[p]) {
    int a = f(i, !t);
    if (a == 1) {
      path.push_back(p);
      return 1;
    }
    r = max(r, a);
  }
  mem[p][t] = r+2;
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int j;
      cin >> j;
      j--;
      node[i].push_back(j);
    }
  }
  int s;
  cin >> s;
  int ans = f(s-1, 0);
  if (ans == 1) {
    cout << "Win" << endl;
    reverse(path.begin(), path.end());
    for (int i : path) cout << i+1 << ' ';
    cout << endl;
  } else {
    cout << (ans == 0 ? "Draw" : "Lose") << endl;
  }
}