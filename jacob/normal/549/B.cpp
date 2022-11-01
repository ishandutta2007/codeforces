#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> res;
  while (true) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
      if (a[i] != 0)
        continue;
      for (int j = 0; j < n; ++j) {
        a[j] -= s[i][j] - '0';
      }
      res.push_back(i + 1);
      found = true;
      break;
    }
    if (!found)
      break;
  }
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (int i = 0; i < (int)res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << endl;
}