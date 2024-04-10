#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i].first;
    d[i].second = i;
  }
  sort(d.rbegin(), d.rend());
  vector<int> lineup(n);
  for (int i = 0; i < n; i++) {
    lineup[i] = d[i].second*2+1;
    if (i) {
      cout << lineup[i-1] << ' ' << lineup[i] << '\n';
    }
  }
  for (int i = 0; i < n; i++) {
    int pos = i+d[i].first;
    assert(pos <= lineup.size());
    cout << lineup[pos-1] << ' ' << d[i].second*2+2 << '\n';
    if (pos == lineup.size()) {
      lineup.push_back(d[i].second*2+2);
    }
  }
}