// Hydro submission #614d3f2c478454b8ebea5c5b@1632452396932
#include <cstdio>
#include <algorithm>

namespace IO {
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
  #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
  inline void flush (){fwrite (obuf, 1, oS - obuf, stdout);oS = obuf;}
  inline void putc (char x){*oS++ = x;if (oS == oT) flush ();}
  template <class I>
  inline void gi (I &x) {
    for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
  }template <class I>
  inline void pr (I x) {
    if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x; while(x) qu[++qr] = x % 10 + '0',  x /= 10; while (qr) putc (qu[qr--]);
  }struct Flusher_ {~Flusher_(){flush();}} io_flusher_;
}using IO::gi;
using IO::putc;
using IO::pr;

const int N = 1e5;
const int INF = 1e9;

int n;
int A[N + 5];

int m;
int B[N + 5];

int Lis[N + 5], Pre[N + 5];
int F[N + 5], G[N + 5], len;

bool Vis[N + 5];

void Solve (int, int);

int main() {
  gi (n);
  for (int i = 1; i <= n; ++i) gi (A[i]);
  gi (m);
  for (int i = 1; i <= m; ++i) gi (B[i]);
  std::sort (B + 1, B + m + 1);

  for (int i = 1; i <= n; ++i)
    if (A[i] != -1) {
      int pos;
      if (A[i] > F[len]) pos = ++len;
      else pos = std::lower_bound (F + 1, F + len + 1, A[i]) - F;
      Pre[i] = G[pos - 1], G[pos]  = i, F[Lis[i] = pos] = A[i];
      
    }else {
      Pre[i] = -1;
      int pos = len;
      for (int j = m; j; --j) {
        while (B[j] <= F[pos]) --pos;
        if (pos == len) ++len;
        F[pos + 1] = B[j], G[pos + 1] = i;
        if (!Lis[i]) Lis[i] = pos + 1;
      }
    }
  int fir;
  for (int i = 1; i <= n; ++i) if (Lis[i] == len) fir = i;
  if (A[fir] == -1) A[fir] = B[m];
  Solve (len - 1, fir);
  
  for (int i = 1; i <= n; ++i) {
    if (A[i] == -1)
      for (int j = 1; j <= m; ++j) if (!Vis[j]) {A[i] = B[j], Vis[j] = true; break;}
    pr (A[i]), putc (' ');
  }
  return 0;

}void Solve (int l, int p) {
  if (l <= 0) return;

  if (Pre[p] != -1) {
    if (A[Pre[p]] == -1)
      for (int i = m; i; --i) if (B[i] < A[p]) {A[Pre[p]] = B[i], Vis[i] = true; break;}
    Solve (l - 1, Pre[p]);
  
  }else {
    int pos = -1;
    for (int i = p - 1; i >= l; --i)
      if (Lis[i] >= l && A[i] != -1 && A[i] < A[p]) pos = i;
    if (pos != -1) Solve (l - 1, pos);
    else {
      for (int i = p - 1; i; --i) if (A[i] == -1) {pos = i; break;}
      for (int i = m; i; --i) if (B[i] < A[p]) {A[pos] = B[i], Vis[i] = true; break;}
      Solve (l - 1, pos);
    }
  }
}