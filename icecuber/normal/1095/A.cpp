#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int j = 0;
  for (int i = 0; j < n; i++) {
    cout << s[j];
    j += i+1;
  }
  cout << endl;
}