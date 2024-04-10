#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string a, b, c;
  cin >> a >> b >> c;
  int ca[26] = {}, cb[26] = {}, cc[26] = {};
  for (char i : a) ca[i-'a']++;
  for (char i : b) cb[i-'a']++;
  for (char i : c) cc[i-'a']++;
  int best = -1, bestb, bestc;
  for (int nb = 0; ; nb++) {
    int ok = 1;
    int ma = 1e9;
    for (int i = 0; i < 26; i++) {
      if (cb[i]*nb > ca[i]) ok = 0;
      if (cc[i])
	ma = min(ma, (ca[i]-cb[i]*nb)/cc[i]);
    }
    if (!ok) break;
    if (nb+ma > best) {
      best = ma+nb;
      bestb = nb;
      bestc = ma;
    }
  }
  for (int i = 0; i < bestb; i++)
    cout << b;
  for (int i = 0; i < bestc; i++)
    cout << c;
  for (int i = 0; i < 26; i++) {
    ca[i] -= bestb*cb[i]+bestc*cc[i];
    for (int j = 0; j < ca[i]; j++)
      cout << char(i+'a');
  }
  cout << endl;
}