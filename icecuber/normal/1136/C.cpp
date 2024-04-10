#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> read(int w, int h) {
  vector<int> r;
  vector<vector<int>> v(w+h);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      int a;
      cin >> a;
      v[i+j].push_back(a);
    }
  for (int i = 0; i < w+h; i++) {
    sort(v[i].begin(), v[i].end());
    for (int j : v[i]) r.push_back(j);
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<int> a = read(w, h), b = read(w, h);
  cout << (a==b ? "YES" : "NO") << endl;
}