#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <bitset>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int L = 70;
const int MAX = 100100;

struct Pt {
  llint x, y;
  llint denom;
};

struct Line {
  llint A, B, C;
} l[MAX];

Line cross(const Line& a, const Line& b) {
  return {a.B*b.C-a.C*b.B, -(a.A*b.C-b.A*a.C), a.A*b.B-a.B*b.A};
}

bool lines_intersection(const Line& a, const Line& b, Pt& ans) {
  Line p = cross(a, b);
  if (p.C == 0) return false;
  ans = {p.A, p.B, p.C};
  return true;
}

bool online(const Line& a, const Pt& p) {
  return a.A*p.x + a.B*p.y + a.C*p.denom == 0;
}

llint get_rand(llint mod) {
  llint a = rand() % (1<<17);
  llint b = rand() % (1<<17);
  return ((a<<17) + b) % mod;
}

bitset<MAX> b[L], tmp, f[10];
int who[10];
int cnt[L];
Pt rp[L];
int m, n, k;

double start;

void rec(int r, int rem) {
  if (rem == 0) {
    puts("YES");
    printf("%d\n", k-r);
    for (int i = k; i > r; --i) {
      int u = -2, v = -2;
      REP(j, n)
        if (b[who[i]].test(j)) {
          if (u == -2) u = j; else
            if (v == -2) v = j;
        }

      printf("%d %d\n", u+1, v+1);
    }
    exit(0);
  }

  if (r == 0) return;

  if ((clock() - start) / CLOCKS_PER_SEC > 1.93) {
    puts("NO");
    exit(0);
  }

  for (int i = 0; i < m; ++i) {
    tmp = b[i] & ~f[r];
    int cc = tmp.count();
    if (cc * r >= rem) {
      who[r] = i;
      f[r-1] = f[r] | b[i];
      rec(r-1, rem - cc);
    }
  }
}

int main(void) {
  start = clock();

  srand(45385111);

  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%lld %lld %lld", &l[i].A, &l[i].B, &l[i].C);

  llint rem = llint(n)*n;
  m = 0;
  REP(ii, 5*L) {
    if (rem == 0 || m == L) break;

    llint idx = get_rand(rem);
    
    REP(i, n) {
      int remi = n;
      bool ima = false;
      REP(j, m)
        if (b[j].test(i)) {
          ima = true;
          remi -= cnt[j]-1;
        }
      remi -= ima;

      if (remi > idx) {
        tmp.reset();
        REP(j, m)
          if (b[j].test(i)) tmp |= b[j];
        
        int f = -1;
        REP(j, n) {
          if (tmp.test(j)) continue;
          if (idx == 0) { f = j; break; }
          --idx;
        }

        assert(f != -1);

        Pt p;
        if (i == f || lines_intersection(l[i], l[f], p)) {
          rp[m] = p;
          if (i == f) {
            cnt[m] = 1;
            b[m].set(i);
          } else {
            REP(j, n)
              if (online(l[j], p)) b[m].set(j), cnt[m]++;
          }
          m++;
          rem -= llint(cnt[m-1])*cnt[m-1];
          break;
        }
      } else {
        idx -= remi;
      }
    }
  }

  rec(k, n);
  puts("NO");
  return 0;
}