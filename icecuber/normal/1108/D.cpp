#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  char last = ' ';
  string r;
  int diffs = 0;
  string rgb = "RGB";
  for (int i = 0; i < n; i++) {
    if (s[i] != last) {
      r += s[i];
    } else {
      set<char> tabu;
      tabu.insert(last);
      if (i < n-1) tabu.insert(s[i+1]);
      char good;
      for (char c : rgb)
	if (!tabu.count(c)) {
	  good = c;
	  break;
	}
      r += good;
      diffs++;
    }
    last = *r.rbegin();
  }
  cout << diffs << endl;
  cout << r << endl;
}