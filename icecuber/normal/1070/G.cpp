#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int s[100], h[100], a[100];
int reachl[100], reachr[100];
int dp[100][100];
int par[100][100];
int parl[100][100];
int parr[100][100];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int minx = 1e9, maxx = -1e9;
  for (int i = 0; i < m; i++) {
    cin >> s[i] >> h[i];
    s[i]--;
    minx = min(minx, s[i]);
    maxx = max(maxx, s[i]);
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    int hp = h[i];
    for (int j = s[i]; j < n; j++) {
      hp += a[j];
      if (hp < 0) break;
      reachr[i] = j;
      dp[s[i]][j] = 1;
      par[s[i]][j] = i;
      parl[s[i]][j] = -1;
      parr[s[i]][j] = j;
    }
    hp = h[i];
    for (int j = s[i]; j >= 0; j--) {
      hp += a[j];
      if (hp < 0) break;
      reachl[i] = j;
      dp[j][s[i]] = 1;
      par[j][s[i]] = i;
      parl[j][s[i]] = -1;
      parr[j][s[i]] = j;
    }
  }

  for (int w = 1; w <= n; w++) {
    for (int l = 0; l+w <= n; l++) {
      int r = l+w-1;
      if (!dp[l][r]) continue;
      //cout << l << ' ' << r << endl;
      for (int i = 0; i < m; i++) {
	if (s[i] < l && reachr[i] >= l-1) {
	  dp[s[i]][r] = 1;
	  par[s[i]][r] = i;
	  parl[s[i]][r] = l;
	  parr[s[i]][r] = r;
	}
	if (s[i] > r && reachl[i] <= r+1) {
	  dp[l][s[i]] = 1;
	  par[l][s[i]] = i;
	  parl[l][s[i]] = l;
	  parr[l][s[i]] = r;
	}
      }
    }
  }
  int l = minx, r = maxx;
  if (!dp[l][r]) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> path;
  while (l > -1) {
    path.push_back(par[l][r]);
    int pl = parl[l][r];
    int pr = parr[l][r];
    l = pl, r = pr;
  }
  cout << r+1 << endl;
  set<int> done;
  reverse(path.begin(), path.end());
  for (int i : path) {
    done.insert(i);
    cout << i+1 << ' ';
  }
  for (int i = 0; i < m; i++) {
    if (!done.count(i))
      cout << i+1 << ' ';
  }
  cout << endl;
}