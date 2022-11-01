#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory.h>
using namespace std;

const int MAXLOGN = 18;
const int MAXN = (1 << MAXLOGN);

vector<int> a[MAXN * 2];
int n;

inline int lower_bound_cnt(const vector<int>& v, int val) {
  return static_cast<int>(lower_bound(v.begin(), v.end(), val) - v.begin());
}

int get_num_less(int l, int r, int v) {
  l += MAXN;
  r += MAXN;
  int res = lower_bound_cnt(a[l], v);
  while (l + 1 != r) {
    if (l % 2 == 0) {
      res += lower_bound_cnt(a[l + 1], v);
    }
    if (r % 2 == 1) {
      res += lower_bound_cnt(a[r - 1], v);
    }
    l /= 2;
    r /= 2;
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a[MAXN + i].push_back(t);
  }
  for (int i = MAXN - 1; i > 0; --i) {
    merge(a[i * 2].begin(), a[i * 2].end(), a[i * 2 + 1].begin(), a[i * 2 + 1].end(), back_inserter(a[i]));
  }
  for (int k = 1; k < n; ++k) {
    int result = 0;
    // i -> [ki + 1 .. ki + k]
    for (int i = 0; k * i + 1 < n; ++i) {
      int l = k * i + 1;
      int r = min(n, k * (i + 1) + 1);
      result += get_num_less(l, r, a[MAXN + i][0]);
    }
    cout << result << " ";
  }
  cout << endl;
}