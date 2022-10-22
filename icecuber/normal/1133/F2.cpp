#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[200000];
int col[200000];
void fill(int p, int c) {
  if (col[p]) return;
  col[p] = c;
  for (int i : node[p]) fill(i,c);
}

int done[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, D;
  cin >> n >> m >> D;
  vector<int> node0;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (!a) node0.push_back(b);
    else if (!b) node0.push_back(a);
    else {
      node[a].push_back(b);
      node[b].push_back(a);
    }
  }
  for (int i = 1; i < n; i++)
    fill(i, i);
  map<int,int> s;
  for (int i : node0)
    s[col[i]] = i;
  if (node0.size() < D || s.size() > D) {
    cout << "NO" << endl;
    return 0;
  }

  vector<pair<int,int>> ans;
  done[0] = 1;
  for (auto p : s) {
    ans.emplace_back(0, p.second);
    done[p.second] = 1;
  }
  for (int i : node0) {
    if (done[i] || ans.size() == D) continue;
    ans.emplace_back(0, i);
    done[i] = 1;
  }

  stack<int> trace;
  for (auto p : ans)
    trace.push(p.second);
  while (trace.size()) {
    int p = trace.top();
    trace.pop();
    for (int i : node[p]) {
      if (done[i]++) continue;
      ans.emplace_back(p, i);
      trace.push(i);
    }
  }
  cout << "YES" << endl;
  for (auto p : ans)
    cout << p.first+1 << ' ' << p.second+1 << endl;
}