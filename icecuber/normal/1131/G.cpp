#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

vector<int> bc[250000], bh[250000];
ll c[10000000], h[10000000];

int tright[10000000], tleft[10000000];
ll dp[10000001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int blocks, n;
  cin >> blocks >> n;
  for (int i = 0; i < blocks; i++) {
    int k;
    cin >> k;
    bh[i].resize(k);
    bc[i].resize(k);
    for (int&v : bh[i]) cin >> v;
    for (int&v : bc[i]) cin >> v;
  }
  int q;
  cin >> q;
  n = 0;
  for (int i = 0; i < q; i++) {
    ll id, mul;
    cin >> id >> mul;
    id--;
    int k = bc[id].size();
    for (int j = 0; j < k; j++) {
      c[n] = bc[id][j]*mul;
      h[n] = bh[id][j];
      n++;
    }
  }
  /*for (int i = 0; i < n; i++) cout << h[i] << ' ';
  cout << endl;
  for (int i = 0; i < n; i++) cout << c[i] << ' ';
  cout << endl;*/

  for (int k = 0; k < 2; k++) {
    vector<pair<int,int>> deq;
    for (int i = n-1; i >= 0; i--) {
      int j = i+h[i];
      while (deq.size() && deq.back().y <= j) deq.pop_back();
      if (deq.size() && deq.back().x < j) j = max(j, deq.back().y), deq.pop_back();
      if (k == 0)
	tright[i] = j-i;
      else
	tleft[n-1-i] = j-i;
      deq.emplace_back(i,j);
    }
    reverse(h, h+n);
  }

  vector<pair<ll,ll>> deq;
  fill_n(dp+1, n, 1e18);
  for (int i = 0; i < n; i++) {
    ll x = i+tright[i], y = dp[i]+c[i];
    if (deq.size() && x == deq.back().x)
      deq.back().y = min(deq.back().y, y);
    else if (deq.empty() || deq.back().y > y)
      deq.emplace_back(x, y);
    dp[i+1] = (i+1 < tleft[i] ? 0 : dp[i+1-tleft[i]])+c[i];

    while (deq.size() && deq.back().x <= i) deq.pop_back();
    if (deq.size())
      dp[i+1] = min(dp[i+1], deq.back().y);
    while (deq.size() && deq.back().x <= i+1) deq.pop_back();
  }
  cout << dp[n] << endl;
}