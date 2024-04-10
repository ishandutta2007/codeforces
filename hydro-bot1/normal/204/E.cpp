// Hydro submission #62a74512cd1ee6a7e16c6f11@1655129363174
#include <bits/stdc++.h>

#define int long long
#define pb push_back

using namespace std;

char __c; bool __f; template <class T> inline void IN(T &x) {
  __f = 0, x = 0; while (__c = getchar (), ! isdigit (__c)) {if (__c == '-') __f = 1;}
  while (isdigit (__c)) {x = x * 10 + __c - '0', __c = getchar ();} if (__f) x = -x;
}

bool START;

const int kN = 2e5 + 5;

int n, k, rt[kN], f[kN], ans[kN], las;
char s[kN];
vector <int> t[kN], v[kN], G[kN];

struct SAM {
  int tr[kN][26], len[kN], cnt = 0, fa[kN];
  
	void Ins(char c) {
    cnt++; int p = las, np = las = cnt; len[np] = len[p] + 1;
    while (p && !tr[p][c]) tr[p][c] = np, p = fa[p];
    if (!p) fa[np] = 1;
    else {
      int q = tr[p][c];
      if (len[q] == len[p] + 1) fa[np] = q;
      else {
	int nq = ++cnt; len[nq] = len[p] + 1, fa[nq] = fa[q], fa[q] = fa[np] = nq;
	for (int i = 0; i < 26; ++i) tr[nq][i] = tr[q][i];
	while (p && tr[p][c] == q) tr[p][c] = nq, p = fa[p];
      }
    }
  }
} sam;

struct Smt {
  int sum[kN * 20], cnt, ls[kN * 20], rs[kN * 20];
#define ls(p) ls[p]
#define rs(p) rs[p]

  void Pushup(int p) {sum[p] = sum[ls(p)] + sum[rs(p)];}
  
  void Modify(int l, int r, int pos, int &p) {
    if (!p) p = ++cnt;
    if (l == r) {sum[p] = 1; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) Modify(l, mid, pos, ls(p));
    else Modify(mid + 1, r, pos, rs(p));
    Pushup(p);
  }

  int Merge(int l, int r, int x, int y) {
    if (!x || !y) return x + y;
    int u = ++cnt;
    if (l == r) {if (sum[x] || sum[y]) sum[u] = 1; return u;}
    int mid = (l + r) >> 1;
    ls(u) = Merge(l, mid, ls(x), ls(y));
    rs(u) = Merge(mid + 1, r, rs(x), rs(y));
    Pushup(u); return u;
  }
} smt;

struct Trie {
  int tr[kN][26], cnt = 0;
  
  void Ins(char *s, int id) {
    int now = 0, len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) {
      int c = s[i] - 'a';
      if (!tr[now][c]) tr[now][c] = ++cnt;
      now = tr[now][c], t[now].pb(id);
    }
  }

  void DFS(int x, int now) {
    for (int i = 0; i < 26; ++i)
      if (tr[x][i]) {
				las = now, sam.Ins(i), DFS(tr[x][i], las);
      }
    for (int i = 0; i < t[x].size(); ++i) smt.Modify(1, n, t[x][i], rt[now]);
    v[now] = t[x];
  }
} trie;

void Add_e(int x, int y) {G[x].pb(y);}

bool END;

void DFS(int x) {
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i]; DFS(to);
    rt[x] = smt.Merge(1, n, rt[x], rt[to]);
    f[x] |= f[to];
  }
  if (!f[x]) f[x] |= (smt.sum[rt[x]] >= k);
}

void DFS2(int x, int res) {
  for (int i = 0; i < G[x].size(); ++i) {
    int to = G[x][i];
    if (f[to]) DFS2(to, sam.len[to]);
    else DFS2(to, res);
  }
  for (int i = 0; i < v[x].size(); ++i) {
    ans[v[x][i]] += res;
  }
}

signed main() {
  //  cout << "Memory : " << (&END - &START) / 1024.0 / 1024.0 << endl;
  sam.cnt = las = 1;
  IN(n), IN(k);
  for (int i = 1; i <= n; ++i) {
    scanf(" %s", s + 1);
    trie.Ins(s, i);
  }
  trie.DFS(0, 1);
  for (int i = 1; i <= sam.cnt; ++i) if (sam.fa[i]) Add_e(sam.fa[i], i);
  DFS(1), DFS2(1, 0);
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  return 0;
}