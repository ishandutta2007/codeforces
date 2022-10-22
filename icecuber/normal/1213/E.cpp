#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<string> cands;
  string a, b;
  for (int i = 0; i < n; i++) {
    a += "abc";
    b += "cba";
  }
  cands.push_back(a);
  cands.push_back(b);
  for (int l = 0; l < 3; l++) {
    string c, d;
    for (int k = 0; k < 3; k++) {
      for (int i = 0; i < n; i++) {
	c += 'a'+(k+l)%3;
	d += 'a'+(2-k+l)%3;
      }
    }
    cands.push_back(c);
    cands.push_back(d);
  }


  string x, y;
  cin >> x >> y;
  for (string s : cands) {
    int ok = 1;
    for (int i = 1; i < n*3; i++) {
      string sub = s.substr(i-1,2);
      if (sub == x || sub == y) ok = 0;
    }
    if (ok) {
      cout << "YES" << endl;
      cout << s << endl;
      return 0;
    }
  }
}