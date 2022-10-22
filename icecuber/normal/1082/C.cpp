#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> a;
  for (int i = 0; i < n; i++) {
    int s, r;
    cin >> s >> r;
    a[s].push_back(r);
  }
  for (auto&p : a) {
    sort(p.second.rbegin(), p.second.rend());
    for (int i = 1; i < p.second.size(); i++)
      p.second[i] += p.second[i-1];
  }
  int k = 1;
  int best = 0;
  while (a.size()) {
    vector<int> todelete;
    int score = 0;
    for (auto&p : a) {
      auto&v = p.second;
      if (v.size() < k || v[k-1] <= 0) todelete.push_back(p.first);
      else score += v[k-1];
    }
    for (int i : todelete)
      a.erase(i);
    best = max(best, score);
    k++;
  }
  cout << best << endl;
}