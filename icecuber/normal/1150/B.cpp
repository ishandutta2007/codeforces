#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s[50];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int j = 1; j < n-1; j++) {
    for (int i = 1; i < n-1; i++) {
      if (s[i][j] == '.' && s[i-1][j] == '.' && s[i+1][j] == '.' && s[i][j-1] == '.' && s[i][j+1] == '.') {
	s[i][j] = '#';
	s[i+1][j] = '#';
	s[i-1][j] = '#';
	s[i][j+1] = '#';
	s[i][j-1] = '#';
      }
    }
  }
  int ok = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] != '#') ok = 0;
  cout << (ok ? "YES" : "NO") << endl;
}