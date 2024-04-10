#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string in, best;
  cin >> n >> in;
  best = in;
  for (int j = 0; j < 10; j++) {
    string s;
    for (char c : in)
      s += (c-'0'+j)%10+'0';
    for (int i = 0; i < n; i++) {
      string v = s.substr(i, n-i)+s.substr(0,i);
      best = min(best, v);
    }
  }
  cout << best << endl;
}