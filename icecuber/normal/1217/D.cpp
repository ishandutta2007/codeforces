#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[5000];
int done[5000];
int n, m;

string ans2;

void dfs(int p) {
  if (done[p] == 1) {
    cout << 2 << endl;
    cout << ans2 << endl;
    cout << endl;
    exit(0);
  }
  if (done[p] == 2) return;
  done[p] = 1;
  for (int i : node[p]) {
    dfs(i);
  }
  done[p] = 2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    ans2 += (a<b ? '1' : '2');
    ans2 += ' ';
    node[a].push_back(b);
  }
  for (int i = 0; i < n; i++) {
    dfs(i);
  }
  cout << 1 << endl;
  for (int i = 0; i < m; i++)
    cout << 1 << ' ';
  cout << endl;
}