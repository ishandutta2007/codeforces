#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 5e5+10;
vector<int> node[nax];

int maxdepth[nax];
int ans[nax*2];

void dfs1(int p, int par) {
  maxdepth[p] = 0;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs1(i, p);
    maxdepth[p] = max(maxdepth[p], maxdepth[i]+1);
  }
}

int maxdeg = 0;
int diam = 0;

vector<int> dfs2(int p, int par, int topdepth = 0) {
  maxdeg = max(maxdeg, (int)node[p].size());
  diam = max(diam, topdepth);

  vector<int> pref = {0}, suf, ind, d;
  for (int i : node[p]) {
    if (i == par) continue;
    pref.push_back(maxdepth[i]+1);
    suf.push_back(maxdepth[i]+1);
    ind.push_back(i);
    d.push_back(maxdepth[i]+1);
  }
  suf.push_back(0);
  for (int i = 0; i < ind.size(); i++)
    pref[i+1] = max(pref[i+1], pref[i]);
  for (int i = ind.size(); i >= 1; i--)
    suf[i-1] = max(suf[i-1], suf[i]);


  d.push_back(topdepth);
  sort(d.rbegin(), d.rend());
  vector<int> ret;
  for (int i = 1; i < d.size(); i++) {
    int v = d[i]*2;
    ans[v] = max(ans[v], i+1);
    ret.push_back(d[i]);
    v = d[i]*2+1 - (d[i-1] == d[i])*2;
    ans[v] = max(ans[v], i+1);
  }

  vector<int> comb;
  for (int i = 0; i < ind.size(); i++) {
    vector<int> c = dfs2(ind[i], p, max(topdepth+1, max(pref[i], suf[i+1])+1));
    for (int j = 0; j < c.size(); j++) {
      if (j == comb.size()) comb.push_back(c[j]);
      else comb[j] = max(comb[j], c[j]);
    }
  }

  {
    int a = 2, b = 2;
    while (a < d.size() && b < comb.size()) {
      int v = min(d[a], comb[b]);
      ans[v*2] = max(ans[v*2], a+b+2 -2);
      if (b+1 == comb.size() || a+1 < d.size() && d[a+1] >= comb[b+1]) {
	a++;
      } else {
	b++;
      }
    }
  }

  return d;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  fill_n(ans+1, n, 1);
  dfs1(0, -1);
  dfs2(0, -1);

  ans[1] = maxdeg+1;
  for (int i = n-2; i >= 1; i--) {
    ans[i] = max(ans[i], ans[i+2]);
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}