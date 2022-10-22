#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 3e5+10;
int pref_mi[nax], pref_ma[nax];
int l[nax], r[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  pref_mi[0] =-1e9;
  pref_ma[0] = 2e9;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    pref_mi[i+1] = max(pref_mi[i], l[i]);
    pref_ma[i+1] = min(pref_ma[i], r[i]);
  }
  int post_mi = -1e9, post_ma = 2e9;
  int ans = 0;
  for (int i = n-1; i >= 0; i--) {
    ans = max(ans, min(post_ma,pref_ma[i])-max(post_mi,pref_mi[i]));
    post_mi = max(post_mi, l[i]);
    post_ma = min(post_ma, r[i]);
  }
  cout << ans << endl;
}