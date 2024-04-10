#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
vector<int> cnt[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vector<pair<int,int>> facs;
    for (int j = 2; j*j <= a; j++) {
      if (a%j == 0) {
	int c = 0;
	while (a%j == 0) {
	  a /= j;
	  c++;
	}
	facs.emplace_back(j, c);
      }
    }
    if (a > 1) {
      facs.emplace_back(a, 1);
    }

    for (auto [p, c] : facs) {
      cnt[p].push_back(c);
    }
  }
  ll ans = 1;
  for (int i = 0; i < nax; i++) {
    sort(cnt[i].begin(), cnt[i].end());
    int c = 0;
    if ((int)cnt[i].size() == n) {
      c = cnt[i][1];
    } else if ((int)cnt[i].size() == n-1) {
      c = cnt[i][0];
    }
    for (int j = 0; j < c; j++)
      ans *= i;
  }
  cout << ans << endl;
}