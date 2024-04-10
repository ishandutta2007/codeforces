#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a[5200];

int check(int x, int n) {
  if (n%x) return 0;
  for (int i = 0; i < n; i+=x)
    for (int j = 0; j < n; j+=x)
      for (int k = 0; k < x; k++)
	for (int l = 0; l < x; l++)
	  if (a[i][j] != a[i+k][j+l]) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n/4; j++) {
      int v = 0;
      if (s[j] <= '9') v = s[j]-'0';
      else v = s[j]-'a'+10;
      for (int k = 0; k < 4; k++)
	a[i] += v>>3-k&1;
    }
  }
  for (int i = n; i; i--)
    if (check(i,n)) {
      cout << i << endl;
      return 0;
    }
}