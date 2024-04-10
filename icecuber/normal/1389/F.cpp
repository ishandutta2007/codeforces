#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<19;
struct segTree {
  vector<ll> off, ma;
  segTree() {
    off.resize(nax*2);
    ma.resize(nax*2);
  }
  void add(int r, ll v) {
    for (int i = r+nax; i > 1; i >>= 1) {
      if (i&1) {
	off[i-1] += v;
      }
      ma[i>>1] = max(ma[i]+off[i], ma[i^1]+off[i^1]);
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int,int,int>> inp(n);
  map<int,int> comp;
  for (auto&[l,r,t] : inp) {
    cin >> l >> r >> t;
    t--;
    l--;
    comp[l];
    comp[r];
  }
  int c = 0;
  for (auto&[p,i] : comp) i = c++;
  vector<vector<vector<int>>> seg(2, vector<vector<int>>(c));
  for (auto&[l,r,t] : inp) {
    seg[t][comp[r]].push_back(comp[l]);
  }
  vector<vector<int>> dp(2, vector<int>(c));
  vector<segTree> tree(2);

  int ans = 0;
  for (int i = 0; i < c; i++) {
    for (int t : {0,1}) {
      for (int j : seg[t][i]) {
	tree[t].add(j+1, 1);
	//for (int k = 0; k <= j; k++)
	//  dp[!t][k]++;
      }
    }
    for (int t : {0,1}) {
      int v = 0;
      //for (int j = i-1; j >= 0; j--) {
      //v = max(v, dp[!t][j]);
      //}
      v = tree[!t].ma[1];
      ans = max(ans, v);
      tree[t].add(i+1,v);
      tree[t].add(i,-v);

      //dp[t][i] = v;
    }
  }
  cout << ans << endl;
}