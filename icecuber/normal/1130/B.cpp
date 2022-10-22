#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> pos[100001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 2*n; i++) {
    int a;
    cin >> a;
    pos[a].push_back(i);
  }
  ll ans = 0;
  ll pa = 0, pb = 0;
  for (int i = 1; i <= n; i++) {
    ans += min(abs(pa-pos[i][0])+abs(pb-pos[i][1]),
	       abs(pb-pos[i][0])+abs(pa-pos[i][1]));
    pa = pos[i][0];
    pb = pos[i][1];
  }
  cout << ans << endl;
}