#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define x first
#define y second

vector<pair<int, ll>> child[1000000];
vector<ll> a;

struct Place {
  int x, y;
  pair<int, int> sides(int i) {
    ll mid = a[x]&~((1LL<<i)-1)|1LL<<i;
    int left = lower_bound(a.begin()+x, a.begin()+y, mid)-a.begin()-x;
    int right = y-x-left;
    return {left,right};
  }
};

void dfs(int p, ll x = 0) {
  //cout << p << endl;
  a.push_back(x);
  //if (p >= 1000000) cout << "ERROR" << endl;
  for (auto i : child[p]) {
    //if (i.first != p+1) cout << "ERROR" << endl;
    dfs(i.first, i.second^x);
  }
}

int main() {
  ios::sync_with_stdio(0);
  ll n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int p;
    ll w;
    cin >> p >> w;
    //if (p < 0 || p > 1000000 || i != p) cout << "ERROR" << endl;
    child[p-1].push_back({i,w});
  }
  dfs(0);
  //return 0;
  sort(a.begin(), a.end());
  ll ans = 0;
  vector<pair<Place, Place>> v;
  int alen = a.size();
  v.push_back({{0,alen},{0,alen}});
  for (int i = 62; i >= 0; i--) {
    ll diffs = 0, eqs = 0;
    for (auto j : v) {
      auto a = j.x.sides(i);
      auto b = j.y.sides(i);
      eqs += 1LL*a.x*b.x+1LL*a.y*b.y;
      diffs += 1LL*a.x*b.y+1LL*a.y*b.x;
    }
    //cout << eqs << ' ' << diffs << endl;
    ll side = 0;
    if (eqs < k) k -= eqs, side = 1;
    ans += side<<i;

    vector<pair<Place, Place>> newv;
    for (auto j : v) {
      auto a = j.x.sides(i);
      auto b = j.y.sides(i);
      if (side==0) {
	if (a.x && b.x)
	  newv.push_back({{j.x.x,j.x.x+a.x},{j.y.x,j.y.x+b.x}});
	if (a.y && b.y)
	  newv.push_back({{j.x.x+a.x,j.x.y},{j.y.x+b.x,j.y.y}});
      } else {
	if (a.x && b.y)
	  newv.push_back({{j.x.x,j.x.x+a.x},{j.y.x+b.x,j.y.y}});
	if (a.y && b.x)
	  newv.push_back({{j.x.x+a.x,j.x.y},{j.y.x,j.y.x+b.x}});
      }
    }
    v = newv;
  }
  cout << ans << endl;
}