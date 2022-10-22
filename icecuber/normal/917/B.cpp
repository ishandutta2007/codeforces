#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 100;
vector<pair<int,char>> node[nax];
int mem[nax][nax][26];
int win(int a, int b, char c) {
  int&memo = mem[a][b][c-'a'];
  if (!memo) {
    int r = 0;
    for (auto [i,e] : node[a]) {
      if (e >= c && !win(b,i,e)) {
	r = 1;
	break;
      }
    }
    memo = r+2;
  }
  return memo-2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].emplace_back(b, c);
  }
  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      cout << (win(a, b, 'a') ? "A" : "B");
    }
    cout << endl;
  }
}