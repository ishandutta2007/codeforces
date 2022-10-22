#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000], take[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int taken = 0;
  vector<pair<int, int>> negatives;
  int ma = -2e9, mai;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0) take[i] = 1, taken++;
    else if (a[i] < 0) negatives.push_back({a[i],i});
    if (a[i] > ma) ma = a[i], mai = i;
  }
  sort(negatives.begin(), negatives.end());
  if (negatives.size() <= 1 && !taken) {
    take[mai] = 1;
  } else {
    for (int i = 0; i+1 < negatives.size(); i += 2)
      take[negatives[i].second] =
	take[negatives[i+1].second] = 1;
  }
  int take0 = -1, notake0 = -1;
  for (int i = 0; i < n; i++) {
    if (take[i]) {
      if (take0 == -1) take0 = i;
      else cout << "1 " << i+1 << ' ' << take0+1 << '\n';
    } else {
      if (notake0 == -1) notake0 = i;
      else cout << "1 " << i+1 << ' ' << notake0+1 << '\n';
    }
  }
  if (notake0 != -1) cout << "2 " << notake0+1 << '\n';
}