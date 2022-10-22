#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int as = count(s.begin(), s.end(), 'a');
  int l = (int(s.size())-as)/2;
  string a, a0, b;
  for (char c : s) {
    if (a0.size() < l || b.empty() && c=='a') {
      a += c;
      if (c != 'a') a0 += c;
    } else
      b += c;
  }
  cout << (a0==b ? a : ":(") << endl;
}