#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  ll ws = 0, wos = 0, wows = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'v' && i && s[i-1] == 'v') ws++, wows += wos;
    else if (s[i] == 'o') wos += ws;
  }
  cout << wows << endl;
}