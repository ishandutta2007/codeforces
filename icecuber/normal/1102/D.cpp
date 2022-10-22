#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int c[3] = {};
  for (int i = 0; i < n; i++)
    c[s[i]-'0']++;
  int g = n/3;
  for (int i = 0; i < n; i++) {
    if (s[i] == '2' && c[2] > g) {
      c[2]--;
      if (c[0] < g) s[i] = '0', c[0]++;
      else s[i] = '1', c[1]++;
    } else if (s[i] == '1' && c[1] > g && c[0] < g) {
      c[1]--, c[0]++;
      s[i] = '0';
    }
  }
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == '0' && c[0] > g) {
      c[0]--;
      if (c[2] < g) s[i] = '2', c[2]++;
      else s[i] = '1', c[1]++;
    } else if (s[i] == '1' && c[1] > g && c[2] < g) {
      c[1]--, c[2]++;
      s[i] = '2';
    }
  }
  cout << s << endl;
}