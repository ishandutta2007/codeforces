// Hydro submission #62ad3a56476f7f4f2b1bb197@1655519831294
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

const int kN = 2e5 + 5;

int n, ans, m;
int a[kN], b[kN];
char s[kN];

struct SAM {
  int las, cnt, tr[kN][26], fa[kN], len[kN], mnp[kN], mxp[kN];
  vector <int> G[kN];

  void Init() {las = cnt = 1;}

  void Add_e(int x, int y) {G[x].pb(y);}
  
  void Ins(char c, int ps) {
    c -= 'A', cnt++;
    int p = las, np = las = cnt; mnp[np] = mxp[np] = ps;
    while (p && !tr[p][c]) tr[p][c] = np, p = fa[p];
    if (!p) fa[np] = 1;
    else {
      int q = tr[p][c];
      if (len[q] == len[p] + 1) fa[np] = q;
      else {
	int nq = ++cnt; len[nq] = len[p] + 1, fa[nq] = fa[q];
	mxp[nq] = mxp[q], mnp[nq] = mnp[q], fa[q] = fa[np] = nq;
	for (int i = 0; i < 26; ++i) tr[nq][i] = tr[q][i];
	while (p && tr[p][c] == q) tr[p][c] = nq, p = fa[p];
      }
    }
  }

  void Build() {
    for (int i = 2; i <= cnt; ++i) Add_e(fa[i], i);
  }

  void DFS(int x) {
    for (int i = 0; i < G[x].size(); ++i) {
      int to = G[x][i]; DFS(to), mxp[x] = max(mxp[x], mxp[to]), mnp[x] = min(mnp[x], mnp[to]);
    }
  }
} sam1, sam2;

bool END;

signed main() {
  //  cout << "Memory : " << (&END - &START) / 1024.0 / 1024.0 << endl;
  sam1.Init(), sam2.Init();
  scanf(" %s", s + 1), n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) sam1.Ins(s[i], i);
  for (int i = n; i >= 1; --i) sam2.Ins(s[i], i);
  sam1.Build(), sam2.Build();
  sam1.DFS(1), sam2.DFS(1), IN(m);
  while (m--) {
    scanf(" %s", s + 1); int len = strlen(s + 1);\
    if (len == 1) continue;
    for (int i = 1, now = 1; i <= len; ++i) now = sam1.tr[now][s[i] - 'A'], a[i] = sam1.mnp[now];
    for (int i = len, now = 1; i >= 1; --i) now = sam2.tr[now][s[i] - 'A'], b[i] = sam2.mxp[now];
    if (a[len]) {ans++; continue;}
    for (int i = 1; i < len; ++i) {
      if (a[i] && b[i + 1] && a[i] < b[i + 1]) {ans++; break;}
    }
  }
  cout << ans << endl;
  return 0;
}