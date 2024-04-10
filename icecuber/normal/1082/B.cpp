#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int golds = 0;
  vector<int> v;
  char last = 'G';
  v.push_back(0);
  for (int j = 0; j < n; j++) {
    if (s[j] != last) v.push_back(1);
    else v[v.size()-1]++;
    last = s[j];
    if (s[j] == 'G') golds++;
  }
  //for (int i : v) cout << i << endl;
  n = v.size();
  int best = 0;
  for (int i = 0; i < n; i += 2) {
    best = max(best, v[i]+((i&&v[i-1] || i<n-1&&v[i+1])&&v[i]<golds));
    if (i<n-2 && v[i+1]==1)
      best = max(best, v[i]+v[i+2]+(v[i]+v[i+2]!=golds));
  }
  cout << best << endl;
}