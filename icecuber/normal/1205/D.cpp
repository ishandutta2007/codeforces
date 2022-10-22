#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[1000];
int sz[1000];
void dfs1(int p, int par = -1) {
  sz[p] = 1;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs1(i,p);
    sz[p] += sz[i];
  }
}

int dp[1010][1010];
int par[1010][1010];

int f(int a, int b) {
  return (a+1)*(b+1)-1;
}

int val[1000];
void dfs2(int p, int&n, int mul, int par) {
  val[p] = n++*mul;
  cout << p+1 << ' ' << par+1 << ' ' << val[p]-val[par] << endl;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs2(i, n, mul, p);
  }
}

int n;
void solve(int center, vector<pair<int,int>>&sizes) {
  /*for (auto p : sizes)
    cout << p.first << ' ' << p.second << endl;
    cout << endl;*/
  fill_n(dp[0], n, 0);
  fill_n(par[0], n, -1);
  dp[0][0] = 1;
  int m = sizes.size();
  for (int k = 0; k < m; k++) {
    for (int j = 0; j < n; j++) {
      dp[k+1][j] = dp[k][j];
      par[k+1][j] = -1;
    }
    int w = sizes[k].first;
    for (int j = 0; j+w < n; j++) {
      if (dp[k][j]) {
	dp[k+1][j+w] = 1;
	par[k+1][j+w] = k;
      }
    }
  }
  /*for (int i = 0; i < n; i++)
    cout << dp[m][i] << ' ';
    cout << endl;*/
  int score = n/2;
  while (dp[m][score] == 0) score--;
  int cp_score = score;

  if (f(score,n-1-score) >= 2*n*n/9) {
    vector<int> a, b;
    for (int k = m; k; k--) {
      if (par[k][score] != -1) {
	score -= sizes[k-1].first;
	a.push_back(k-1);
      } else b.push_back(k-1);
    }

    int sum = 0;
    for (int i : a) {
      sum += sizes[i].first;
    }
    assert(sum == cp_score);
    for (int i : b) {
      sum += sizes[i].first;
    }
    assert(sum == n-1);

    int na = 1, nb = 1;
    for (int i : a) {
      dfs2(sizes[i].second, na, 1, center);
    }
    for (int i : b) {
      dfs2(sizes[i].second, nb, na, center);
    }
    exit(0);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs1(0);
  vector<int> perm(n);
  for (int i = 0; i < n; i++)
    perm[i] = i;
  mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(perm.begin(), perm.end(), mrand);
  for (int pi = 0; pi < n; pi++) {
    int i = perm[pi];
    vector<pair<int,int>> sizes;
    int ma = 0;
    for (int j : node[i]) {
      int s = sz[j];
      if (s > sz[i]) {
	s = n-sz[i];
      }
      sizes.push_back({s,j});
      ma = max(ma, s);
    }
    int sum = 0;
    for (auto p : sizes) sum += p.first;
    assert(sum == n-1);

    #warning TODO
    /*if (ma >= n/2) {
      int score = f(ma,n-1-ma);
      if (score >= 2*n*n/9) {
	solve(i, sizes);
	return 0;
      }
      continue;
      }*/
    solve(i, sizes);
  }
}