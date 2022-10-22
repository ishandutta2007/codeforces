#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr << #x << " = " << (x) << endl;

string s[500];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  int ans = 0;
  int dx[5] = {0,1,1,-1,-1};
  int dy[5] = {0,-1,1,-1,1};
  for (int i = 1; i < n-1; i++) {
    for (int j = 1; j < n-1; j++) {
      int ok = 1;
      for (int k = 0; k < 5; k++)
	if (s[i+dy[k]][j+dx[k]] != 'X') ok = 0;
      ans += ok;
    }
  }
  cout << ans << endl;
}