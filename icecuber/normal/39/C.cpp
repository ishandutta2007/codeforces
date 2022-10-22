#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

struct Crater {
  int s, e, i;
};

Crater c[2010];
int dp[2010];
vector<int> child[2010];
int dp2[4010], par2[4010];

void dfs(int p) {
  if (c[p].i)
    cout << c[p].i << ' ';
  for (int i : child[p])
    dfs(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int ci, ri;
    cin >> ci >> ri;
    c[i].s = ci-ri;
    c[i].e = ci+ri;
    c[i].i = i+1;
  }
  c[n].s = -2.1e9, c[n].e = 2.1e9, c[n].i = 0;
  n++;

  map<int,int> ma;
  for (int i = 0; i < n; i++)
    ma[c[i].s], ma[c[i].e];
  int m = 0;
  for (auto&p : ma) p.second = m++;
  for (int i = 0; i < n; i++)
    c[i].s = ma[c[i].s], c[i].e = ma[c[i].e];

  int ans = -1, besti;
  sort(c, c+n, [](Crater a, Crater b) {return a.e-a.s < b.e-b.s;});
  for (int i = 0; i < n; i++) {
    fill_n(dp2, m, 0);
    fill_n(par2, m, -1);
    vector<vector<int>> v(m);
    for (int j = 0; j < i; j++)
      if (c[j].s >= c[i].s && c[j].e <= c[i].e)
	v[c[j].s].push_back(j);

    int best = 0, bestp = 0;
    for (int p = 0; p < m; p++) {
      if (p && dp2[p] < dp2[p-1]) {
	dp2[p] = dp2[p-1];
	par2[p] = par2[p-1];
      }
      if (dp2[p] > best) {
	best = dp2[p];
	bestp = p;
      }
      for (int j : v[p]) {
	if (dp2[c[j].e] < dp2[p]+dp[j]) {
	  dp2[c[j].e] = dp2[p]+dp[j];
	  par2[c[j].e] = j;
	}
      }
    }
    dp[i] = best+1;
    //cout << c[i].s << ' ' << c[i].e << ' ' << dp[i] << endl;
    if (dp[i] > ans) {
      ans = dp[i];
      besti = i;
    }
    for (; par2[bestp] != -1; bestp = c[par2[bestp]].s)
      child[i].push_back(par2[bestp]);
  }
  /*for (int i = 0; i < n; i++) {
    cout << c[i].i << ": ";
    for (int j : child[i])
      cout << c[j].i << ' ';
    cout << endl;
    }*/
  cout << ans-1 << endl;
  dfs(besti);
  cout << endl;
}