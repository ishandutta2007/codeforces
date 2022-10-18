#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 101000;
const int K = 150;
const int MAXK = MAXN/K;

// 0 A - cesti brojevi, ima ih malo
// 1 B - rijetki brojevi, ima ih puno

int F[MAXK][MAXN]; // F[x][i] -> kolko puta se A(x) pojavljuje do i-te pozicije
int L[K][MAXN]; // L[x][i] -> kolko ima brojeva u skupu B koji se pojavljuju x puta do i-te pozicije

int a[MAXN]; // prvi redak
int tip[MAXN];

int A[MAXK]; // skup cestih brojeva
int indA[MAXN]; // indeks cestog broja u skupu A

int invM[MAXN];
queue<int> Q; // slboodni indeksi, za sazimanje
map<int, int> M; // sazimanje
set<int> S[MAXN]; // S[x] -> sve pozicije na kojima se x pojavljuje

int n;

void add(int *L, int x, int v) {
  for (++x; x < MAXN; x += x&-x)
    L[x] += v;
}
int sum(int *L, int x) {
  int r = 0;
  for (++x; x; x -= x&-x)
    r += L[x];
  return r;
}

void insert(int i, int x) {
  if (!M.count(x)) {
    M[x] = Q.front();
    invM[Q.front()] = x;
    tip[Q.front()] = 1;
    Q.pop();
  }
  x = M[x];
  a[i] = x;
  
  if (tip[x] == 1) {
    int cnt = 0, cntLess = 0;
    for (int p: S[x]) {
      cnt++;
      if (p > i) {
        add(L[cnt], p, -1);
        add(L[cnt+1], p, +1); 
      } else
        cntLess++;
    }
    S[x].insert(i);
    add(L[cntLess+1], i, +1);
    
    if (S[x].size() == K-1) { // prebaci iz B u A
      indA[x] = -1;
      REP(j, MAXK)
        if (A[j] == -1) { indA[x] = j; break; }
      A[indA[x]] = x;

      int cnt = 0;
      for (int p: S[x]) {
        cnt++;
        add(L[cnt], p, -1);
        add(F[indA[x]], p, +1);
      }

      tip[x] = 0;
    }
  } else {
    add(F[indA[x]], i, +1);
    S[x].insert(i);
  }
}

void erase(int i) {
  int x = a[i];
  
  if (tip[x] == 1) {
    int cnt = 0, cntLess = 0;
    for (int p: S[x]) {
      cnt++;
      if (p > i) {
        add(L[cnt], p, -1); 
        add(L[cnt-1], p, +1);
      } else
        cntLess++;
    }
    add(L[cntLess], i, -1);
    S[x].erase(i);
    
    if (S[x].size() == 0) {
      Q.push(x);
      M.erase(invM[x]);
    }
  } else {
    add(F[indA[x]], i, -1);
    S[x].erase(i);

    if (S[x].size() == K-2) { // prebaci iz A u B
      int cnt = 0;
      for (int p: S[x]) {
        cnt++;
        add(L[cnt], p, +1);
        add(F[indA[x]], p, -1);
      }
      A[indA[x]] = -1;
      tip[x] = 1;
    }
  }
}

int query(int x, int y) {
  if (x >= 1) x = 2 - (x%2);

  if (x == 0) return invM[a[y]];
  
  if (x == 1) {
    int num = a[y];
    if (tip[num] == 1) {
      int cnt = 0;
      for (int p: S[num]) {
        cnt++;
        if (p == y) break;
      }
      return cnt;
    } else {
      return sum(F[indA[num]], y);
    }
  }

  // x == 2
  int num = query(1, y);
  int ans = 0;

  if (num < K) ans += sum(L[num], y);
  REP(i, MAXK)
    if (A[i] != -1 && sum(F[i], y) >= num) ans++;
  return ans;
}

int main(void) {
  scanf("%d", &n);

  REP(i, n) Q.push(i);
  REP(i, MAXK) A[i] = -1;

  REP(i, n) {
    int x;
    scanf("%d", &x);
    insert(i, x);
  }

  int m;
  scanf("%d", &m);
  REP(i, m) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    
    if (t == 1) {
      --y;
      erase(y);
      insert(y, x);
    } else {
      --x, --y;
      printf("%d\n", query(x, y));
    }
  }
  return 0;
}