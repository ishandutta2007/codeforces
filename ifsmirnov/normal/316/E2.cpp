#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
const int maxn = 200500;
const int mod = 1000000000;
typedef long long i64;
inline int madd(int x, int y) { return (x + y) % mod; }
inline int mmul(int x, int y) { return (i64)x*y%mod; }

struct node
{
  node *L, *R;
  int add;
  int s, sum; // s - only fib, sum - reali

  node(int l, int r, int a[], int f[]) : add(0)
  {
    if (l == r) {
      L = R = NULL;
      s = f[l];
      sum = mmul(f[l], a[l]);
    }
    else {
      L = new node(l, (l+r)/2, a, f);
      R = new node((l+r)/2+1, r, a, f);
      s = madd(L->s, R->s);
      sum = madd(L->sum, R->sum);
    }
  }
  void push()
  {
    if (add) {
      if (L) {
        L->sum = madd(L->sum, mmul(add, L->s));
        R->sum = madd(R->sum, mmul(add, R->s));
        L->add = madd(L->add, add);
        R->add = madd(R->add, add);
      }
    }
    add = 0;

    if (L) {
      sum = madd(L->sum, R->sum);
    }
  }
  void paint(int lq, int rq, int x, int l, int r)
  {
    if (lq <= l && rq >= r) {
      add = madd(add, x);
      sum = madd(sum, mmul(x, s));
    }
    else if (lq > r || rq < l)
      ;
    else {
      push();
      L->paint(lq, rq, x, l, (l+r)/2);
      R->paint(lq, rq, x, (l+r)/2+1, r);
      push();
    }
  }
  int get(int lq, int rq, int l, int r) {
    push();
    if (lq <= l && rq >= r)
      return sum;
    else if (lq > r || rq < l)
      return 0;
    else {
      push();
      return madd(L->get(lq, rq, l, (l+r)/2), R->get(lq, rq, (l+r)/2+1, r));
    }
  }
  void pset(int i, int x, int l, int r) {
    push();
    if (l == r)
      sum = mmul(s, x);
    else if (i <= (l+r)/2)
      L->pset(i, x, l, (l+r)/2);
    else
      R->pset(i, x, (l+r)/2+1, r);
    push();
  }
};

int n, m;
int a[maxn];
int fib[maxn];

node *ta, *tb;

void scan()
{
  scanf("%d%d", &n, &m);
  forn(i, n) scanf("%d", &a[i]);
}

void prepare_trees()
{
  fib[0] = 0; fib[1] = 1;
  forn(i, n) if (i >= 2) fib[i] = madd(fib[i-1], fib[i-2]);
  ta = new node(0, n-1, a, fib);

  fib[0] = 1; fib[1] = 1;
  forn(i, n) if (i >= 2) fib[i] = madd(fib[i-1], fib[i-2]);
  tb = new node(0, n-1, a, fib);
}

void solve()
{
  prepare_trees();

  forn(i, m) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int p, x;
      scanf("%d%d", &p, &x); --p;
      ta->pset(p, x, 0, n-1);
      tb->pset(p, x, 0, n-1);
    }
    else if (t == 2) {
      int l, r;
      scanf("%d%d", &l, &r); --l; --r;
      int a = ta->get(l, r, 0, n-1), b = tb->get(l, r, 0, n-1);

      int res;
      if (l == 0) res = b;
      else if (l == 1) res = a;
      else {
        res = madd(mmul(b, fib[l-2]), -mmul(a, fib[l-1]));
        if (l%2 == 1) res *= -1;
        res %= mod;
        while (res < 0)
          res += mod;
      }
      //printf("%d\n", b);
      printf("%d\n", res);
    }
    else {
      int l, r, d;
      scanf("%d%d%d", &l, &r, &d); --l; --r;
      ta->paint(l, r, d, 0, n-1);
      tb->paint(l, r, d, 0, n-1);
    }
  }
}

void gen()
{
  freopen("input.txt", "w", stdout);
  int n = 100, m = 100;
  cout << n << " " << m << endl;
  forn(i, n) cout << rand()%10000 << " "; cout << endl;
  forn(i, m) {
    int t = rand()%3;
    cout << t+1 << " ";
    if (t == 0) cout << rand()%n+1 << " " << rand()%10000 << endl;
    else {
      int l = rand()%n, r = rand()%n;
      if (l > r) swap(l, r);
      if (t == 1) cout << l+1 << " " << r+1 << endl;
      else cout << l+1 << " " << r+1 << " " << rand()%1000 << endl;
    }
  }
  exit(0);
}

int main()
{
  //gen();
  //freopen("input.txt", "r", stdin);

  scan();
  solve();

  return 0;
}