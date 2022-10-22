#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string a, b;
  cin >> a >> b;
  int sumb = 0;
  for (char c : b) sumb ^= c-'0';
  int suma = 0, ans = 0;
  for (int i = 0; i < a.size(); i++) {
    suma ^= a[i]-'0';
    if (i >= b.size()) suma ^= a[i-b.size()]-'0';
    if (i+1 >= b.size())
      ans += suma==sumb;
  }
  cout << ans << endl;
}