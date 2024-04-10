// Hydro submission #62ad2b2802aab04f3f7bf600@1655515945320
#include <bits/stdc++.h>

#define int long long
#define Low(x) (x & (-x))
#define pb push_back

using namespace std;

char __c; bool __f; template <class T> inline void IN(T &x) {
  __f = 0, x = 0; while (__c = getchar (), ! isdigit (__c)) {if (__c == '-') __f = 1;}
  while (isdigit (__c)) {x = x * 10 + __c - '0', __c = getchar ();} if (__f) x = -x;
}

bool START;

const int kN = 105, kM = 1e3 + 5, kMod = 1e9 + 9;

int n, m, tr[kN][26], fa[kN], cnt, v[kN];
int f[kM][kN][15];
char s[kN];
vector <int> G[kN];

void Add_e(int x, int y) {G[x].pb(y);}

struct AC {
  void Ins(char *s) {
    int len = strlen(s), now = 0;
    for (int i = 0; i < len; ++i) {
      int c = s[i] - 'A';
      if (!tr[now][c]) tr[now][c] = ++cnt;
      now = tr[now][c];
    } v[now] = len;
  }

  void Build() {
    queue <int> q;
    for (int i = 0; i < 26; ++i) if (tr[0][i]) q.push(tr[0][i]), Add_e(0, tr[0][i]);
    while (!q.empty()) {
      int x = q.front(); q.pop();
      for (int i = 0; i < 26; ++i) {
	if (tr[x][i]) fa[tr[x][i]] = tr[fa[x]][i], Add_e(fa[tr[x][i]], tr[x][i]), q.push(tr[x][i]);
	else tr[x][i] = tr[fa[x]][i];
      }
    }
  }
} AC;

void DFS(int x, int res) {
  res = max(res, v[x]), v[x] = res;
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i]; DFS(to, res);
  }
}

bool END;

signed main() {
  //  cout << "Memory : " << (&END - &START) / 1024.0 / 1024.0 << endl;
  IN(n), IN(m);
  for (int i = 1; i <= m; ++i) scanf(" %s", s), AC.Ins(s);
  AC.Build(), DFS(0, 0);
  f[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= cnt; ++j) {
      for (int k = 0; k <= 11; ++k) {
	for (int l = 0; l < 26; ++l) {
	  int to = tr[j][l];
	  if (v[to] >= k + 1)
	    f[i + 1][to][0] = (f[i + 1][to][0] + f[i][j][k]) % kMod;
	  else
	    f[i + 1][to][k + 1] = (f[i + 1][to][k + 1] + f[i][j][k]) % kMod;
	}
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= cnt; ++i) ans = (ans + f[n][i][0]) % kMod;
  cout << ans << endl;
  return 0;
}