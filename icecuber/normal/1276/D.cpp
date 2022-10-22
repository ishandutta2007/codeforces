#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

const int nax = 2e5;
vector<int> node[nax];

ll take[nax], leave[nax], taken[nax];

void dfs(int p, int par) {
  vector<ll> pref = {1}, mid, suf;
  int bef = -1, count = 0;
  for (int i : node[p]) {
    if (i == par) {
      bef = count;
    } else {
      dfs(i, p);
      pref.push_back(leave[i]);
      mid.push_back(take[i]);
      suf.push_back(taken[i]);
      count++;
    }
  }
  if (bef == -1) bef = count;

  for (int i = 0; i+1 < pref.size(); i++) {
    (pref[i+1] *= pref[i]) %= mod;
  }
  suf.push_back(1);
  for (int i = (int)suf.size()-1; i; i--) {
    (suf[i-1] *= suf[i]) %= mod;
  }
  leave[p] = (pref[bef]*suf[bef])%mod;
  for (int i = 0; i < bef; i++) {
    (leave[p] += pref[i]*mid[i]%mod *suf[i+1]) %= mod;
  }
  take[p] = pref.back();
  for (int i = bef; i+1 < suf.size(); i++) {
    (take[p] += pref[i]*mid[i]%mod *suf[i+1]) %= mod;
  }
  taken[p] = pref.back();
  for (int i = 0; i+1 < suf.size(); i++) {
    (taken[p] += pref[i]*mid[i]%mod *suf[i+1]) %= mod;
  }

  if (pref.size() == 1) {
    leave[p] = take[p] = taken[p] = 1;
  }
  //cout << p+1 << ' ' << leave[p] << ' ' << take[p] << ' ' << taken[p] << endl;
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

  dfs(0, -1);
  cout << (taken[0]%mod+mod)%mod << endl;
}