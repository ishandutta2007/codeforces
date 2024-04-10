#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int adj[26][26];
int done[26];
void dfs(int p) {
  if (done[p]++) return;
  for (int i = 0; i < 26; i++)
    if (adj[p][i]) dfs(i);
}

int main() {
  int n;
  cin >> n;
  int has[26] = {};
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int c[26] = {};
    for (char ch : s) c[ch-'a']++;
    for (int j = 0; j < 26; j++) {
      has[j] |= !!c[j];
      for (int k = 0; k < j; k++) {
	if (c[j] && c[k]) {
	  adj[j][k] |= 1;
	  adj[k][j] |= 1;
	}
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (!has[i]) continue;
    ans += !done[i];
    dfs(i);
  }
  cout << ans << endl;
}