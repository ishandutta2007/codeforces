#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> eq[2000], node[2000];
int groups = 0;

int col[2000];
vector<int> clist[2001];
void fill(int p, int c) {
  if (col[p]) return;
  col[p] = c;
  clist[c].push_back(p);
  for (int i : eq[p]) fill(i, c);
}

int ans[2000];
int done[2001];
int dp[2001];
void dfs(int p) {
  if (done[p] == 1) {
    cout << "No" << endl;
    exit(0);
  }
  if (done[p] == 2) return;
  done[p] = 1;

  dp[p] = 1;
  for (int i : clist[p])
    for (int j : node[i]) {
      dfs(col[j]);
      dp[p] = max(dp[p], dp[col[j]]+1);
    }
  for (int i : clist[p])
    ans[i] = dp[p];
  done[p] = 2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '=') {
	eq[i].push_back(j+n);
	eq[j+n].push_back(i);
      } else if (s[j] == '>')
	node[i].push_back(j+n);
      else
	node[j+n].push_back(i);
    }
  }

  for (int i = 0; i < n+m; i++) {
    if (col[i]) continue;
    fill(i,++groups);
  }

  for (int i = 1; i <= groups; i++)
    dfs(i);
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;
  for (int i = 0; i < m; i++)
    cout << ans[i+n] << ' ';
  cout << endl;
}