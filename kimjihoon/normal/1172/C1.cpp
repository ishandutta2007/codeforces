#include <iostream>
using namespace std;

long long md = 998244353;

struct ns
{
   long long a, b;
   ns operator*(const ns &r) const {
      ns t;
      t.a = (a * r.a) % md; t.b = (b * r.b) % md;
      return t;
   }
   ns operator+(const ns &r) const {
      ns t;
      t.a = (((a * r.b) % md) + ((r.a * b) % md)) % md;
      t.b = (b * r.b) % md;
      return t;
   }
   ns(long long a, long long b) : a(a), b(b) {};
   ns() : a(0LL), b(0LL) {};
};

long long fp(long long n, long long k)
{
   long long s = 1;
   while (k) {
      if (k % 2LL) s = (s * n) % md;
      k /= 2LL; n = (n * n) % md;
   }
   return s;
}

ns d[59][59][59], ans[59];
int n, m, a[59];
long long s, s0, s1, w[59];

void ps(int pi)
{
   for (int i = 0; i <= m; i++)
      for (int j = 0; j <= m; j++)
         for (int k = 0; k <= m; k++)
            d[i][j][k] = ns(0, 1);
   d[0][0][0] = ns(1, 1);
   ans[pi] = ns(0, 1);
   for (long long i = 0; i <= m; i++)
      for (long long j = 0; j <= i; j++)
         for (long long k = 0; k <= i - j; k++) {
            long long r, sp;
            if (a[pi] == 0) r = -(i - j - k);
            else r = (i - j - k);
            sp = s - j + k + r;
            r = w[pi] + r;
            if (a[pi] == 0 && (s0 - j - w[pi] < 0 || r < 0)) continue;
            if (a[pi] == 1 && s0 - j < 0) continue;
            if (i == m) {
               ans[pi] = ans[pi] + (ns(r, 1) * d[i][j][k]);
               continue;
            }
            if (a[pi] == 0) {
               if (s0 - j - w[pi] > 0) d[i + 1][j + 1][k] = d[i + 1][j + 1][k] + (d[i][j][k] * ns(s0 - j - w[pi], sp));
               d[i + 1][j][k + 1] = d[i + 1][j][k + 1] + (d[i][j][k] * ns(s1 + k, sp));
               if (r > 0) d[i + 1][j][k] = d[i + 1][j][k] + (d[i][j][k] * ns(r, sp));
            }
            else {
               if (s0 - j > 0) d[i + 1][j + 1][k] = d[i + 1][j + 1][k] + (d[i][j][k] * ns(s0 - j, sp));
               if (s1 + k - w[pi] > 0) d[i + 1][j][k + 1] = d[i + 1][j][k + 1] + (d[i][j][k] * ns(s1 + k - w[pi], sp));
               d[i + 1][j][k] = d[i + 1][j][k] + (d[i][j][k] * ns(r, sp));
            }
         }
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);   
   cin >> n >> m;
   for (int i = 0; i < n; i++)
      cin >> a[i];
   for (int i = 0; i < n; i++) {
      cin >> w[i];
      s += w[i];
      if (a[i] == 0) s0 += w[i];
      else s1 += w[i];
   }
   for (int i = 0; i < n; i++) {
      ps(i);
      long long p = ans[i].a, q = ans[i].b;
      cout << fp((fp(p, md - 2) * q) % md, md - 2) << '\n';
   }
   return 0;
}