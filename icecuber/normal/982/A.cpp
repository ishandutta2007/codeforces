#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ok = 1;
  for (int i = 0; i+2 <= n; i++)
    if (s.substr(i,2) == "11") ok = 0;
  for (int i = 0; i+3 <= n; i++)
    if (s.substr(i,3) == "000") ok = 0;
  if (n >= 2)
    if (s.substr(0,2) == "00" || s.substr(s.size()-2, 2) == "00")
      ok = 0;
  if (n == 1 && s == "0") ok = 0;
  cout << (ok ? "Yes" : "No") << endl;
}