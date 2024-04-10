#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int j = (s.size()-1)/2, k = 1;
  string ans;
  for (int i = 0; i < s.size(); i++) {
    ans += s[j];
    j += k;
    if (k > 0) k = -k-1;
    else k = -k+1;
  }
  cout << ans << endl;
}