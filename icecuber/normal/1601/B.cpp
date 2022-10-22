#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int&v : a) cin >> v;
  for (int&v : b) cin >> v;

  int mi = n-1;
  vector<int> par(n, -1), jmp(n, -1), dist(n, 1e9);

  queue<int> q;
  dist[n-1] = 0;
  q.push(n-1);
  while (q.size()) {
    int p = q.front();
    q.pop();

    int reach = p-a[p];   
    if (reach == -1) {
      /*cout << p << endl;
      for (int i = 0; i < n; i++) cout << par[i] << ' ';
      cout << endl;*/

      vector<int> path;
      while (p != n-1) {
        path.push_back(jmp[p]+1);
        p = par[p];
      }
      reverse(path.begin(), path.end());
      path.push_back(0);
      cout << path.size() << endl;
      for (int i : path) cout << i << ' ';
      cout << endl;
      return 0;
    }
    while (reach < mi) {
      mi--;
      int j = mi+b[mi];
      if (dist[j] != 1e9) continue;
      q.push(j);
      dist[j] = dist[p]+1;
      par[j] = p;
      jmp[j] = mi;
    }
  };
  cout << -1 << endl;
}