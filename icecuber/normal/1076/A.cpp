#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  string r;
  int done = 0;
  for (int i = 0; i < n; i++) {
    if (!done && (i == n-1 || s[i+1] < s[i])) done = 1;
    else r += s[i];
  }
  cout << r << endl;
}