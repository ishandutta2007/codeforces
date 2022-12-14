#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int N = 200000 + 10, S = 26;

class SAM {
  int next[N][S], pre[N], len[N], cnt[N], q[N], sum[N], last, tot;
 public:
  void clear() {
    memset(next, 0, sizeof next);
    memset(pre, 0, sizeof pre);
    memset(len, 0, sizeof len);
    memset(cnt, 0, sizeof cnt);
    last = tot = 1;
  }
  void append(int c) {
    int np = ++tot, p = last;
    len[np] = len[p] + 1;
    cnt[np] = 1;
    for (; p && !next[p][c]; p = pre[p]) next[p][c] = np;
    if (!p) {
      pre[np] = 1;
    } else {
      int q = next[p][c];
      if (len[q] == len[p] + 1) {
        pre[np] = q;
      } else {
        int nq = ++tot;
        memcpy(next[nq], next[q], sizeof next[q]);
        pre[nq] = pre[q];
        len[nq] = len[p] + 1;
        pre[q] = pre[np] = nq;
        for (; p && next[p][c] == q; p = pre[p]) next[p][c] = nq;
      }
    }
    last = np;
  }
  i64 dp() {
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= tot; ++i) ++sum[len[i]];
    for (int i = 1; i <= tot; ++i) sum[i] += sum[i - 1];
    for (int i = 1; i <= tot; ++i) q[sum[len[i]]--] = i;
    for (int i = tot; i > 0; --i) {
      int a = q[i], b = pre[a];
      cnt[b] += cnt[a];
    }
    i64 res = 0;
    for (int i = 2; i <= tot; ++i) res += ((i64)len[i] - len[pre[i]]) * cnt[i] * cnt[i];
    return res;
  }
} sam;

int main() {
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    static char s[N];
    scanf(" %s", s);
    sam.clear();
    for (char *i = s; *i; ++i) sam.append(*i - 'a');
    printf("%lld\n", sam.dp());
  }
}