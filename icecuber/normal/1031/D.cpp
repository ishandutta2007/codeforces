#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int nota[2000][2000];
string s[2000];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  int best = -1;
  set<pair<int, int>> besti;
  nota[0][0] = s[0][0]!='a';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i|j)
	nota[i][j] = min(i?nota[i-1][j]:1<<30, j?nota[i][j-1]:1<<30)+(s[i][j]!='a');
      if (nota[i][j] <= k && i+j > best) {
	best = i+j;
	besti.clear();
      }
      if (nota[i][j] <= k && i+j == best)
	besti.insert({j,i});
    }
  string ans;
  for (int i = 0; i <= best; i++) ans += 'a';
  if (!besti.size()) {
    ans = s[0][0];
    besti.insert({0,0});
  }
  while (ans.size() < n*2-1) {
    set<pair<int, int>> next_best;
    char bestc = 'z';
    for (pair<int, int> p : besti) {
      if (p.x < n-1 && s[p.y][p.x+1] <= bestc) {
	if (s[p.y][p.x+1] < bestc) next_best.clear();
	bestc = s[p.y][p.x+1];
	next_best.insert({p.x+1,p.y});
      }
      if (p.y < n-1 && s[p.y+1][p.x] <= bestc) {
	if (s[p.y+1][p.x] < bestc) next_best.clear();
	bestc = s[p.y+1][p.x];
	next_best.insert({p.x,p.y+1});
      }
    }
    ans += bestc;
    besti = next_best;
  }
  cout << ans << endl;
}