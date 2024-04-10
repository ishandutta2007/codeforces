#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> queries[300000];
vector<int> node[300000];

long long ans[300000];
long long value[300002];
int id = 0;
void dfs(int p, int par = -1, int depth = 1, long long sum = 0) {
  for (auto q : queries[p]) {
    value[min(depth+q.first, 300001)] += q.second;
    sum += q.second;
    //cout << q.second << endl;
  }
  sum -= value[depth-1];
  ans[p] = sum;
  //cout << p+1 << ' ' << sum << endl;
  for (int i : node[p]) {
    if (i != par) {
      dfs(i, p, depth+1, sum);
    }
  }
  sum += value[depth+1];
  for (auto q : queries[p]) {
    value[min(depth+q.first, 300001)] -= q.second;
  }
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int v, d, x;
    cin >> v >> d >> x;
    v--;
    queries[v].push_back({d,x});
  }
  dfs(0);
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}