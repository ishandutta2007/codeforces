#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  char minc = 'z';
  for (int i = 0; i < s.size(); i++) {
    cout << (s[i] > minc ? "Ann" : "Mike") << '\n';
    minc = min(minc, s[i]);

  }
}