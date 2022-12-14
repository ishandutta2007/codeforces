#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;
using r32 = double;
using r64 = long double;

template <class T>
inline bool relax(T &a, T b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool tense(T &a, T b) {
  return b < a ? a = b, true : false;
}

const int N = 111111;
const int M = 255;

int n, m;
char s[N];
int goes[N][26], last[26];
char a[3][M];
int len[3];
int f[M][M][M];

inline void trans(int i, int j, int k) {
  f[i][j][k] = n + 1;
  if (i) {
    tense(f[i][j][k], goes[f[i - 1][j][k]][a[0][i] - 'a']);
  }
  if (j) {
    tense(f[i][j][k], goes[f[i][j - 1][k]][a[1][j] - 'a']);
  }
  if (k) {
    tense(f[i][j][k], goes[f[i][j][k - 1]][a[2][k] - 'a']);
  }
}

int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);

  scanf("%d %d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 0; i < 26; ++i) {
    last[i] = goes[n + 1][i] = n + 1;
  }
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      goes[i][j] = last[j];
    }
    if (i) {
      last[s[i] - 'a'] = i;
    }
  }

  while (m--) {
    char t[3], c[3];
    int v;
    scanf("%s", t);
    if (t[0] == '+') {
      scanf("%d%s", &v, c);
      --v;
      a[v][++len[v]] = c[0];
      if (v == 0) {
        for (int i = 0; i <= len[1]; ++i) {
          for (int j = 0; j <= len[2]; ++j) {
            trans(len[0], i, j);
          }
        }
      } else if (v == 1) {
        for (int i = 0; i <= len[0]; ++i) {
          for (int j = 0; j <= len[2]; ++j) {
            trans(i, len[1], j);
          }
        }
      } else {
        for (int i = 0; i <= len[0]; ++i) {
          for (int j = 0; j <= len[1]; ++j) {
            trans(i, j, len[2]);
          }
        }
      }
    } else {
      scanf("%d", &v);
      --v;
      --len[v];
    }
    puts(f[len[0]][len[1]][len[2]] <= n ? "YES" : "NO");
  }

  return 0;
}