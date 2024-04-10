#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1000;
int er[nax][nax], ec[nax][nax];
char ans[nax][nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> er[i][j] >> ec[i][j];
      er[i][j]--, ec[i][j]--;
    }
  queue<pair<int,int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (er[i][j] == -2) {
	for (int d = 0; d < 4; d++) {
	  int nr = i+(d==0)-(d==1);
	  int nc = j+(d==2)-(d==3);
	  if (nc < 0 || nr < 0 || nc >= n || nr >= n) continue;
	  if (!ans[nr][nc] && er[nr][nc] == -2 && ec[nr][nc] == -2) {
	    ans[nr][nc] = "UDLR"[d];
	  }
	}
      } else {
	ans[er[i][j]][ec[i][j]] = 'X';
	q.emplace(er[i][j], ec[i][j]);
      }
    }
  }
  while (q.size()) {
    auto [r,c] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nr = r+(d==0)-(d==1);
      int nc = c+(d==2)-(d==3);
      if (nc < 0 || nr < 0 || nc >= n || nr >= n) continue;
      if (!ans[nr][nc] && er[nr][nc] == er[r][c] && ec[nr][nc] == ec[r][c]) {
	ans[nr][nc] = "UDLR"[d];
	q.emplace(nr,nc);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!ans[i][j] ||
	  (ans[i][j] == 'X' && (er[i][j] != i || ec[i][j] != j))) {
	cout << "INVALID" << endl;
	return 0;
      }
    }
  }
  cout << "VALID" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j];
    cout << endl;
  }
}