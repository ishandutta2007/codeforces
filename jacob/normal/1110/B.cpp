#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> m >> n >> k;
  vector<int> b;
  for (int i = 0; i < m; ++i) {
    int bb;
    cin >> bb;
    b.push_back(bb);
  }
  sort(b.begin(), b.end());
  int total = b.back() - b.front() + 1;
  vector<int> v;
  for (int i = 0; i < m - 1; ++i) {
    v.push_back(b[i + 1] - b[i] - 1);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size() && i < k - 1; ++i) {
    total -= v[i];
  }
  cout << total << endl;
  return 0;
}