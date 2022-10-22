#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int zeros = count(s.begin(), s.end(), '0');
  int ones = count(s.begin(), s.end(), '1');
  int qs = count(s.begin(), s.end(), '?');
  ones -= (int(s.size())+1)/2-1;
  zeros -= int(s.size())/2-1;
  if (zeros+qs >= 2) cout << "00" << endl;
  string a = s, b = s;
  int a0 = zeros, b1 = ones;
  int la0 = 1e9, la1 = -1e9;
  int lb0 = 1e9, lb1 = -1e9;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      if (a0 < 1)
	a[i] = '0', a0++;
      else a[i] = '1';
      if (b1 < 1)
	b[i] = '1', b1++;
      else b[i] = '0';
    }
    if (a[i] == '0') la0 = i;
    else la1 = i;
    if (b[i] == '0') lb0 = i;
    else lb1 = i;
  }
  if (a0 == 1 && b1 == 1) {
    if(la0 < la1)
      cout << "01" << endl;
    if (lb0 > lb1)
      cout << "10" << endl;
  }
  if (ones+qs >= 2) cout << "11" << endl;
}