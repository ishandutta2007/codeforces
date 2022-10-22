#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    char c = (!i&&n>1)+'0';
    if (!k || s[i] == c) continue;
    s[i] = c;
    k--;
  }
  cout << s << endl;
}