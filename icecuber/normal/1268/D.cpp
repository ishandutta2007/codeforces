#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<2000> adj[2000];

bitset<2000> dfs(int start) {
  bitset<2000> seen;
  stack<int> todo;
  todo.push(start);
  seen.set(start);
  while (todo.size()) {
    int p = todo.top();
    todo.pop();
    bitset<2000> news = adj[p] & ~seen;
    seen |= news;
    while (news.any()) {
      int i = news._Find_first();
      todo.push(i);
      news.set(i,0);
    }
  }
  return seen;
}

int check(int n) {
  bitset<2000> mask;
  for (int i = 0; i < n; i++) mask.set(i);

  for (int k : {0,1}) {
    bitset<2000> seen = dfs(0);
    if (seen.count() != n) return 0;

    for (int i = 0; i < n; i++) {
      adj[i] ^= mask;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      adj[i].set(j, s[j]-'0');
    }
  }
  if (check(n)) {
    cout << 0 << ' ' << 1 << endl;
  } else {
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	adj[i].flip(j);
	adj[j].flip(i);
      }
      if (check(n)) count += 1;
      for (int j = 0; j < n; j++) {
	adj[i].flip(j);
	adj[j].flip(i);
      }
    }

    if (count) {
      cout << 1 << ' ' << count << endl;
    } else {
      // Split into 2 SCC


      bitset<2000> mask;
      for (int i = 0; i < n; i++) mask.set(i);

      bitset<2000> seen = dfs(0);
      int base;
      if (seen.count() == n)
	base = 0;
      else
	base = (~seen)._Find_first();

      for (int i = 0; i < n; i++)
	adj[i] ^= mask;

      int a = dfs(base).count();
      a = min(a, n-a);
      if (a == 1 && n-a == 3) {
	cout << -1 << endl;
      } else {
	cout << 2 << ' ' << 2 * a * (n-a) << endl;
      }
    }
  }
}