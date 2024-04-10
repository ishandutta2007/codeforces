#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }

  auto apply_split = [&](const vector<int>& split) {
    vector<int> na;
    int start = 0;
    for (int x : split) {
      assert(x > 0);
      for (int i = 0; i < x; ++i) {
        na.insert(na.begin(), a[start + x - i - 1]);
      }
      start += x;
    }
    assert(start == n);
    a = na;
  };

  vector<vector<int>> ret;
  for (int i = n - 1; i > 0; --i) {
    int pos = std::find(a.begin(), a.end(), i) - a.begin();

    bool flipped = ret.size() % 2;

    vector<int> split;
    if (!flipped) {
      if (pos == i) continue;
      assert(pos < i);
      if (pos > 0) split.push_back(pos);
      split.push_back(i - pos + 1);
      for (int j = i + 1; j < n; ++j) split.push_back(1);
    } else {
      if (pos == n - i - 1) continue;
      assert(pos > n - i - 1);
      for (int j = i + 1; j < n; ++j) split.push_back(1);
      split.push_back(pos - (n - i - 1) + 1);
      if (pos < n - 1) split.push_back(n - 1 - pos);
    }
    ret.push_back(split);
    apply_split(split);
  }

  if (ret.size() % 2) {
    ret.push_back(vector<int>(n, 1));
    apply_split(ret.back());
  }

  for (int i = 0; i < n; ++i) assert(a[i] == i);

  int cnt = 0;
  for (auto& split : ret)
    if (split.size() > 1) cnt++;

  cout << cnt << '\n';
  for (auto& split : ret) {
    if (split.size() == 1) continue;
    cout << split.size();
    for (int x : split) cout << ' ' << x;
    cout << '\n';
  }

  return 0;
}