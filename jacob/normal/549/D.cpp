#include <iostream>
#include <string>
using namespace std;

int ma[100][100];

int n, m;

int main(void) {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
  {
    string str;
    cin >> str;
    for (int j = 0; j < m; ++j) {
      ma[i][j] = (str[j] == 'B') ? 1 : -1;
    }
  }
  int ans = 0;
  while (true) {
    int ni = -1, nj = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (ma[i][j] != 0) {
          ni = i;
          nj = j;
        }
      }
    }
    if (ni == -1)
      break;
    ++ans;
    for (int i = 0; i <= ni; ++i)
      for (int j = 0; j <= nj; ++j)
        ma[i][j] -= ma[ni][nj];
  }
  cout << ans << endl;
}