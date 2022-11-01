#include <set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

set<char> pattern = { 'f', 'a', 'c', 'e' };

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<string> ma(n);
  for (int i = 0; i < n; ++i)
    cin >> ma[i];
  int res = 0;
  for (int i = 0; i < n - 1; ++i)
    for (int j = 0; j < m - 1; ++j) {
      set<char> s = { ma[i][j], ma[i + 1][j], ma[i][j + 1], ma[i + 1][j + 1] };
      if (s == pattern)
        ++res;
    }
  cout << res << endl;
}