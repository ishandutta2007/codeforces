#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod;
int bin_pow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

struct Path {
  int end;
  vector<int> v;
};
bool operator<(Path a, Path b) {
  return a.end < b.end;
}
bool operator==(Path a, Path b) {
  return a.end == b.end;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int u, v;
  cin >> u >> v >> mod;
  vector<vector<Path>> qa, qb;
  qa.push_back({});
  qb.push_back({});
  qa.back().push_back({u,{}});
  qb.back().push_back({v,{}});
  for (int d = 0; ; d++) {
    for (auto&q_ : {&qa, &qb}) {
      auto&q = *q_;
      sort(q.back().begin(), q.back().end());
      q.back().resize(unique(q.back().begin(), q.back().end())-q.back().begin());
      q.push_back({});
      for (Path p : q[d]) {
	int a = (p.end+1)%mod;
	int b = (p.end+mod-1)%mod;
	int c = bin_pow(p.end, mod-2);
	p.v.push_back(1);
	q[d+1].push_back({a, p.v});
	p.v.back() = 2;
	q[d+1].push_back({b, p.v});
	p.v.back() = 3;
	q[d+1].push_back({c, p.v});
      }

      map<int,int> ma;
      for (int i = 0; i < (int)qa.back().size(); i++) {
	ma[qa.back()[i].end] = i;
      }
      for (Path p : qb.back()) {
	if (ma.count(p.end)) {
	  vector<int> ans = qa.back()[ma[p.end]].v;
	  reverse(p.v.begin(), p.v.end());
	  int trans[] = {0,2,1,3};
	  for (int i : p.v) {
	    ans.push_back(trans[i]);
	  }
	  cout << ans.size() << endl;
	  for (int i : ans) cout << i << ' ';
	  cout << endl;
	  return 0;
	}
      }
    }
  }
}