#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    v[i] += i;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; ++i) {
    if (v[i] == v[i + 1])
    {
      cout << ":(" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << v[i] - i << " ";
  }
  cout << endl;
}