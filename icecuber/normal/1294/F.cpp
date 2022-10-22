#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];

int ans = 0;
int ansa = 0, ansb = -1, ansc = -1;

pair<pair<int,int>,pair<int,pair<int,int>>> dfs(int p, int par = -1) {
  vector<pair<int,int>> va;
  vector<pair<int,pair<int,int>>> vb;

  pair<int,int> amax = {-1,-1};
  pair<int,pair<int,int>> bmax = {-1,{-1,-1}};
  for (int i : node[p]) {
    if (i == par) continue;
    auto [ca, cb] = dfs(i, p);
    {
      {
	int sc = ca.first+bmax.first+2;
	if (sc > ans) {
	  ans = sc;
	  ansa = ca.second;
	  tie(ansb, ansc) = bmax.second;
	}
      }
      {
	int sc = amax.first+cb.first+2;
	if (sc > ans) {
	  ans = sc;
	  ansa = amax.second;
	  tie(ansb, ansc) = cb.second;
	}
      }
    }
    amax = max(amax, ca);
    bmax = max(bmax, cb);
    va.push_back(ca);
    vb.push_back(cb);
  }
  if (va.empty()) {
    return {{0,p},{0,{p,-1}}};
  }
  sort(va.rbegin(), va.rend());
  sort(vb.rbegin(), vb.rend());
  auto a = make_pair(va[0].first+1, va[0].second);
  auto b = make_pair(vb[0].first+1, vb[0].second);

  if ((int)va.size() >= 2) {
    int sb = va[0].first+va[1].first+2;
    if ((int)va.size() >= 2 && sb > b.first) {
      b = {sb, {va[0].second, va[1].second}};
    }
  }

  /*int sc = va[0].first+vb[0].first+2;
  if (sc > ans) {
    ans = sc;
    ansa = va[0].second;
    tie(ansb, ansc) = vb[0].second;
    }*/

  if ((int)va.size() >= 3) {
    int sd = va[0].first+va[1].first+va[2].first+3;
    if (sd > ans) {
      ans = sd;
      ansa = va[0].second;
      ansb = va[1].second;
      ansc = va[2].second;
    }
  }
  //cout << p+1 << ' ' << a.first << ' ' << b.first << endl;
  return {a, b};
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
  dfs(0);
  cout << ans << endl;
  set<int> taken;
  for (int v : {ansa,ansb,ansc}) {
    if (v < 0 || taken.count(v)) {
      v = 0;
      while (taken.count(v)) v++;
    }
    taken.insert(v);
    cout << v+1 << ' ';
  }
  cout << endl;
}