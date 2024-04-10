#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void brute() {
  set<int> s;
  for (int i = 104; i <= 107; i++)
    for (int j = 107; j <= 120; j++)
      s.insert(i^j);
  int l = -10;
  vector<pair<int,int>> ans;
  int b = -10;
  s.insert(1e9);
  for (int i : s) {
    if (i == l+1) {

    } else {
      if (b > -1)
	cout << b << ".." << l << endl;
      b = i;
    }
    l = i;
  }
  cout << endl;
}

vector<pair<ll,ll>> split(ll l, ll r) {
  if (l == r) return {{l,0}};
  int j = 60;
  while (((l^r)>>j)==0) j--;
  ll m = (1ll<<j)-1;
  return {{l-(l&m)^m, (l&m)^m}, {r-(r&m), r&m}};
}

ll join(ll a, ll b) {
  ll r = a|b;
  for (int j = 0; (a&b)>>j; j++)
    r |= 1ll<<j;
  return r;
}

vector<pair<ll,ll>> f(ll al, ll ar, ll bl, ll br) {
  vector<pair<ll,ll>> ans;
  for (auto a : split(al,ar)) {
    for (auto b : split(bl,br)) {
      ll x = a.first^b.first;
      ll r = join(a.second, b.second);
      //cout << x << ' ' << r << endl;
      r++;
      for (int j = 0; j <= 60; j++) {
	if (r>>j&1) {
	  ll L = (r>>j+1<<j+1) ^ (x>>j<<j);
	  ans.emplace_back(L, L+(1ll<<j));
	}
      }
    }
  }
  return ans;
}

int main() {
  /*for (auto p : split(1, 9))
    cout << p.first << ' ' << p.second << endl;
    return 0;
  */

  ios::sync_with_stdio(0); cin.tie(0);
  int na;
  cin >> na;
  vector<pair<ll,ll>> a(na);
  for (auto&p : a) cin >> p.first >> p.second;
  int nb;
  cin >> nb;
  vector<pair<ll,ll>> b(nb);
  for (auto&p : b) cin >> p.first >> p.second;

  vector<pair<ll,ll>> e;
  for (auto pa : a)
    for (auto pb : b)
      for (auto p : f(pa.first, pa.second, pb.first, pb.second)) {
	//cout << pa.first << ' ' << pa.second << ' ' << pb.first << ' ' << pb.second << ' ' << p.first << ' ' << p.second << endl;
	e.emplace_back(p.first, p.second);
      }

  sort(e.begin(), e.end());

  const ll mod = 998244353;
  ll ans = 0;
  ll reach = -1;
  for (auto p : e) {
    //cout << p.first << ' '<< p.second << endl;
    if (p.second > reach) {
      ll l = max(p.first, reach)%mod, r = p.second%mod;
      //cout << l << ' ' << r << endl;
      (ans += (r*(r-1)%mod-l*(l-1)%mod)*((mod+1)/2)) %= mod;
      reach = p.second;
    }
  }
  cout << (ans%mod+mod)%mod << endl;
}