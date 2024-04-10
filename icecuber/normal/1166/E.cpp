#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<10000> a[50];

vector<int> node[50];

int done[50];
int ok = 1;
void dfs(int p) {
  if (done[p] == 1) ok = 0;
  if (done[p]) return;
  done[p] = 1;
  for (int i : node[p]) dfs(i);
  done[p] = 2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--;
      a[i].set(v);
    }
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      if ((~a[i]&a[j])==a[j]) node[i].push_back(j);
  for (int i = 0; i < m; i++)
    dfs(i);
  cout << (ok ? "possible" : "impossible") << endl;
}