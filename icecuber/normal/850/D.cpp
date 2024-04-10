#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 100;

int adj[nax][nax];

void construct(set<pair<int,int>> left) {
  int len = left.size();
  for (int i = 0; i < len; i++) {
    auto it = left.begin();
    auto [deg, a] = *it;
    left.erase(it);

    set<pair<int,int>> nxt;

    int k = 0;
    for (auto [d, b] : left) {
      int dir = (k++ < deg);
      adj[a][b] = dir;
      nxt.insert({d-!dir, b});
      adj[b][a] = !dir;
    }
    left = nxt;
  }

  cout << len << endl;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++)
      cout << adj[i][j];
    cout << endl;
  }
}



int a[31];
int mem[nax*30][nax][31], par[nax*30][nax][31];
int ok(int sum, int len, int mii) {
  if (sum < 0 || len < 0 || sum < len*(len-1)/2) return 0;
  if (len == 0) return sum == 0 && mii == -1;
  if (mii < 0) return 0;
  int&memo = mem[sum][len][mii];
  if (!memo) {
    int r =
      ok(sum-a[mii], len-1, mii-1) ||
      ok(sum-a[mii], len-1, mii);
    par[sum][len][mii] = ok(sum-a[mii], len-1, mii-1);
    memo = r+1;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  for (int len = 0; len < nax; len++) {
    if (ok(len*(len-1)/2, len, n-1)) {
      int sum = len*(len-1)/2, l = len, mii = n-1;
      set<pair<int,int>> d;
      for (int it = 0; it < len; it++) {
	d.insert({a[mii],it});
	int dmi = par[sum][l][mii];
	sum -= a[mii];
	l--;
	mii -= dmi;
      }
      assert(!sum);

      construct(d);
      return 0;
    }
  }

  cout << "=(" << endl;
}