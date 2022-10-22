#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int adj[3][3];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    char a = s[0], b = s[2];
    if (s[1] == '<') swap(a,b);
    adj[a-'A'][b-'A']++;
  }
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      for (int c = 0; c < 3; c++) {
	if (a == b || a == c || b == c) continue;
	if (adj[a][b] || adj[a][c] || adj[b][c]) continue;
	string ans;
	ans += char(a+'A');
	ans += char(b+'A');
	ans += char(c+'A');
	cout << ans << endl;
	return 0;
      }
    }
  }
  cout << "Impossible" << endl;
}