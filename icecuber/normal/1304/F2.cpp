#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[50][20000];
ll acc[51][20001];

const int nax = 1<<15;
struct segtree {
  ll ma[nax*2];
  segtree(int n) {
    assert(n < nax);
    fill_n(ma, nax, -1e15);
  }
  void set(int i, ll v) {
    ma[i+=nax] = v;
    for (i >>= 1; i; i >>= 1) {
      ma[i] = max(ma[i*2],ma[i*2+1]);
    }
  }
  ll query(int a, int b, int l = 0, int r = nax, int i = 1) {
    if (a <= l && b >= r) {
      return ma[i];
    } else if (b <= l || a >= r) return -1e15;
    else {
      int mid = l+r>>1;
      return max(query(a, b, l, mid, i*2),
		 query(a, b, mid, r, i*2+1));
    }
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, r;
  cin >> n >> m >> r;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      acc[i+1][j+1] = a[i][j]+acc[i+1][j]+acc[i][j+1]-acc[i][j];
    }

  auto area = [&](int r0, int c0, int r1, int c1) {
    r1 = min(r1, n);
    c1 = min(c1, m);
    if (c0 >= c1 || r0 >= r1) return 0ll;
    return acc[r1][c1]+acc[r0][c0]-acc[r0][c1]-acc[r1][c0];
  };

  vector<int> dp(m+1);
  for (int i = 0; i < n; i++) {
    vector<int> ndp(m+1);
    segtree tree0(m+1), tree1(m+1), tree2(m+1);
    for (int j = 0; j <= m; j++) {
      tree0.set(j, dp[j]-area(i,0,i+1,j+r));
      tree1.set(j, dp[j]+area(i,0,i+1,j));
      tree2.set(j, dp[j]);
    }
    for (int j = 0; j <= m; j++) {
      ll base = area(i,j,i+2,j+r);
      ndp[j] = max({(ll)ndp[j],
	    tree0.query(j-r,j)+area(i,0,i+1,j) + base,
	    tree1.query(j,j+r)-area(i,0,i+1,j+r) + base,
	    tree2.query(0,j-r) + base,
	    tree2.query(j+r,m+1) + base});
    }
    /*for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= m; k++) {
	ndp[j] = max(ndp[j], dp[k] + area(i,j,i+2,j+r) - area(i,max(j,k),i+1,min(j,k)+r));
      }
      }*/
    swap(dp, ndp);
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}