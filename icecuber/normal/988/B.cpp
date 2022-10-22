#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  sort(s.begin(), s.end(), [](string a, string b) {return a.size() < b.size();});
  for (int i = 1; i < n; i++) {
    string a = s[i-1], b = s[i];
    int ok = 0;
    for (int i = 0; i+a.size() <= b.size(); i++)
      if (b.substr(i, a.size()) == a) ok = 1;
    if (!ok) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (string v : s) cout << v << endl;
}