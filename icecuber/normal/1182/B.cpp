#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[500];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  int stars = 0;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++)
      stars += s[i][j] == '*';
  }
  for (int i = 1; i < h-1; i++) {
    for (int j = 1; j < w-1; j++) {
      if (s[i][j] == '*' &&
	  s[i-1][j] == '*' &&
	  s[i+1][j] == '*' &&
	  s[i][j-1] == '*' &&
	  s[i][j+1] == '*') {
	stars--;
	for (int k = i+1; k < h && s[k][j] == '*'; k++) stars--;
	for (int k = i-1; k >= 0 && s[k][j] == '*'; k--) stars--;
	for (int k = j+1; k < w && s[i][k] == '*'; k++) stars--;
	for (int k = j-1; k >= 0 && s[i][k] == '*'; k--) stars--;
	cout << (stars == 0 ? "YES" : "NO") << endl;
	return 0;
      }
    }
  }
  cout << "NO" << endl;
}