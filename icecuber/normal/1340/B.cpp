#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int can[2010][2010];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<string> digit = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
  int n, k;
  cin >> n >> k;
  vector<string> inp(n);
  for (string&s : inp) cin >> s;
  can[n][0] = 1;
  for (int i = n-1; i >= 0; i--) {
    for (int d = 0; d < 10; d++) {
      int need = 0, ok = 1;
      for (int j = 0; j < 7; j++) {
	int has = inp[i][j]-'0';
	int target = digit[d][j]-'0';
	if (has && !target) ok = 0;
	if (target && !has) need++;
      }
      if (ok) {
	for (int j = need; j <= k; j++) {
	  can[i][j] |= can[i+1][j-need];
	}
      }
    }
  }
  if (can[0][k] == 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int d = 9; d >= 0; d--) {
      int need = 0, ok = 1;
      for (int j = 0; j < 7; j++) {
	int has = inp[i][j]-'0';
	int target = digit[d][j]-'0';
	if (has && !target) ok = 0;
	if (target && !has) need++;
      }
      if (ok && k >= need && can[i+1][k-need]) {
	cout << d;
	k -= need;
	break;
      }
    }
  }
  cout << endl;
}