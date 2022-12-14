#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2000;

int n;
char s[MaxN + 2], t[MaxN + 2];

bool book[MaxN + 1];

int main() {
  cin >> n;
  cin >> s + 1;

  for (int k = n; k; --k) {
    int l = k + 1 >> 1, cur = 0;
    for (int i = 1; i <= n; ++i) {
      cur += !book[i];
      if (cur == l) {
        t[i] = s[n - k + 1];
        book[i] = true;
        break;
      }
    }
  }

  cout << t + 1 << endl;

  return 0;
}