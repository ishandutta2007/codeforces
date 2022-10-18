#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef bitset<1000> bset;

const int MAX = 100100;
const int off = 1<<17;

int a[MAX];
int st[MAX], en[MAX];
vector<int> E[MAX];

int prop[2*off];
bset T[2*off];
bset mask[1000];
int t, m;

void rotate(int i, int k) {
  prop[i] = (prop[i] + k) % m;
  T[i] = (T[i]<<k) | ((T[i] & mask[k]) >> (m-k));
}

void propagate(int i) {
  if (prop[i]) {
    if (i < off) {
      rotate(i*2, prop[i]);
      rotate(i*2+1, prop[i]);
    }
    prop[i] = 0;
  }
}

void update(int i, int lo, int hi, int a, int b, int k) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    rotate(i, k);
    return;
  }
  propagate(i);
  update(i*2, lo, (lo+hi)/2, a, b, k);
  update(i*2+1, (lo+hi)/2, hi, a, b, k);
  T[i] = T[i*2] | T[i*2+1];
}

void query(int i, int lo, int hi, int a, int b, bset& v) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    v |= T[i];
    return;
  }
  propagate(i);
  query(i*2, lo, (lo+hi)/2, a, b, v);
  query(i*2+1, (lo+hi)/2, hi, a, b, v);
}

void dfs(int x, int dad) {
  st[x] = t++;
  for (int y: E[x])
    if (y != dad) dfs(y, x);
  en[x] = t;
}

int main(void) {
  int n;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  FOR(i, 1, m) {
    mask[i] = mask[i-1];
    mask[i].set(m-i);
  }

  dfs(0, -1);
  REP(i, n) T[off+st[i]].set(a[i] % m);
  for (int i = off-1; i > 0; --i)
    T[i] = T[i*2] | T[i*2+1];
  
  int q;
  scanf("%d", &q);

  bset primes;
  FOR(i, 2, m) {
    bool isprime = true;
    FOR(j, 2, i)
      if (i % j == 0) { isprime = false; break; }
    if (isprime) primes.set(i);
  }

  REP(i, q) {
    int tip;
    scanf("%d", &tip);
    if (tip == 1) {
      int v, x;
      scanf("%d %d", &v, &x);
      --v; x %= m;
      update(1, 0, off, st[v], en[v], x);
    }
    if (tip == 2) {
      int v;
      scanf("%d", &v); --v;

      static bset ans;
      ans.reset();
      query(1, 0, off, st[v], en[v], ans);
      ans &= primes;
      printf("%d\n", (int)ans.count());
    }
  }

  return 0;
}