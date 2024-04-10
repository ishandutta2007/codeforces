#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int ans = (s.size()+1)/2;
  if (count(s.begin(),s.end(),'0')+1 == s.size() && s.size()%2 == 1 || s == "0") ans--;
  cout << ans << endl;
}