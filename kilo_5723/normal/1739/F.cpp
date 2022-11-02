#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 5e4 + 5, alpha = 12, maxm = 12, inf = 1e9;
struct AcAuto {
  AcAuto *next, *ch[alpha];
  int val, dp[1 << alpha], move[1 << alpha];
  AcAuto() {
    next = NULL;
    memset(ch, 0, sizeof(ch));
    val = 0;
    memset(dp, -1, sizeof(dp));
    memset(move, -1, sizeof(-1));
  }
};
AcAuto *root;
char s[alpha << 2];
int l, r;
bool vis[alpha];
bool trans(string str) {
  string res;
  int p = alpha << 1;
  memset(vis, false, sizeof(vis));
  memset(s, 0, sizeof(s));
  l = alpha << 2;
  r = 0;
  for (auto ch : str) {
    if (vis[ch - 'a']) {
      if (s[p - 1] == ch)
        p--;
      else if (s[p + 1] == ch)
        p++;
      else
        return false;
    } else {
      vis[ch - 'a'] = true;
      if (!s[p - 1])
        s[--p] = ch;
      else if (!s[p + 1])
        s[++p] = ch;
      else
        return false;
    }
    l = min(l, p);
    r = max(r, p);
  }
  s[++r] = 0;
  return r - l > 1;
}
void add(AcAuto *&u, char *s, int v) {
  if (!u) u = new AcAuto;
  if (!*s) {
    u->val += v;
    return;
  }
  add(u->ch[*s - 'a'], s + 1, v);
}
void build(AcAuto *root) {
  queue<AcAuto *> que;
  que.push(root);
  while (que.size()) {
    auto u = que.front();
    que.pop();
    for (int i = 0; i < alpha; i++)
      if (auto v = u->ch[i]) {
        auto w = u->next;
        while (w && !w->ch[i]) w = w->next;
        v->next = w ? w->ch[i] : root;
        v->val += v->next->val;
        // if (v->next != root) puts("check");
        que.push(v);
      }
  }
}
int dfs(AcAuto *u, int b) {
  if (~u->dp[b]) return u->dp[b];
  int move = -1, mxm = 0;
  for (int i = 0; i < alpha; i++)
    if (!(b >> i & 1)) {
      auto v = u;
      while (v && !v->ch[i]) v = v->next;
      v = v ? v->ch[i] : root;
      auto tmp = dfs(v, b + (1 << i));
      if (tmp >= mxm) {
        mxm = tmp;
        move = i;
      }
    }
  u->move[b] = move;
  return u->dp[b] = u->val + mxm;
}
int main() {
  int n;
  cin >> n;
  root = new AcAuto;
  while (n--) {
    int k;
    string str;
    cin >> k >> str;
    if (trans(str)) {
      // puts("1");
      add(root, s + l, k);
      // printf("%s\n", s + l);
      reverse(s + l, s + r);
      add(root, s + l, k);

      // printf("%s\n", s + l);
    }
  }
  build(root);
  dfs(root, 0);
  // printf("%d\n", dfs(root, 0));
  auto u = root;
  int c, b = 0;
  while (~(c = u->move[b])) {
    putchar('a' + c);
    while (u && !u->ch[c]) u = u->next;
    u = u ? u->ch[c] : root;
    b += (1 << c);
  }
  puts("");
  return 0;
}