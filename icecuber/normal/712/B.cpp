#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  if (s.size()%2) {
    cout << -1 << endl;
    return 0;
  }
  map<char, int> m;
  for (char c : s)
    m[c]++;
  int x = m['R']-m['L'];
  int y = m['U']-m['D'];
  cout << (abs(x)+abs(y)+1)/2 << endl;
}