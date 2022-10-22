#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<pair<int,int>, int>> a, b;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x < y) a.push_back({{x,y},i+1});
    else b.push_back({{x,y},i+1});
  }
  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());
  auto c = (a.size() > b.size() ? a : b);
  cout << c.size() << endl;
  for (auto p : c) cout << p.second << ' ';
  cout << endl;
}