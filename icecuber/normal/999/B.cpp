#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    if (n%i) continue;
    reverse(s.begin(), s.begin()+i);
  }
  cout << s << endl;
}