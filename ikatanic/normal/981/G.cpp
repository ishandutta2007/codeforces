#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXBUFF = 1<<20;

namespace IO {
  char buffer[MAXBUFF], *p = buffer+MAXBUFF;

  inline char read_char() {
    if (p == buffer+MAXBUFF) {
      fread(buffer, 1, MAXBUFF, stdin);
      p = buffer;
    }
    return *p++;
  }

  inline int read_int() {
    char c;
    while (!isdigit(c = read_char()));
    int ret = c-'0';
    while (isdigit(c = read_char())) ret = ret*10 + c-'0';
    return ret;
  }
};

typedef long long llint;

const int off = 1<<18;
const int mod = 998244353;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int S[2*off], P[2*off], R[2*off];

void pushDown(int i) {
  if (P[i] == 1 && R[i] == 0) return;

  R[i] = mul(R[i], (mod + 1) / 2);

  for (int x: {i*2, i*2+1}) {
    S[x] = add(mul(S[x], P[i]), R[i]);
    P[x] = mul(P[x], P[i]);
    R[x] = add(mul(R[x], P[i]), R[i]);
  }
  P[i] = 1;
  R[i] = 0;
}

void mulv(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    P[i] = mul(P[i], 2);
    S[i] = mul(S[i], 2);
    R[i] = mul(R[i], 2);
    return;
  }

  pushDown(i);
  mulv(i*2, lo, (lo+hi)/2, a, b);
  mulv(i*2+1, (lo+hi)/2, hi, a, b);

  S[i] = add(S[i*2], S[i*2+1]);
}

void addv(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    R[i] = add(R[i], hi - lo);
    S[i] = add(S[i], hi - lo);
    return;
  }

  pushDown(i);
  addv(i*2, lo, (lo+hi)/2, a, b);
  addv(i*2+1, (lo+hi)/2, hi, a, b);

  S[i] = add(S[i*2], S[i*2+1]);
}


int sum(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return 0;
  if (lo >= a && hi <= b) return S[i];

  pushDown(i);

  return add(sum(i*2, lo, (lo+hi)/2, a, b), sum(i*2+1, (lo+hi)/2, hi, a, b));
}

map<int, set<pair<int, int>>> M;

void query_add(int l, int r, int x) {
  auto& S = M[x];

  vector<pair<int, int>> v;

  auto it = S.lower_bound({l, -1});
  if (it != S.begin()) {
    --it;
    if (it->second <= l) {
      ++it;
    }
  }

  auto it_start = it;
  while (it != S.end()) {
    int il = max(l, it->first);
    int ir = min(r, it->second);
    if (il >= ir) break;
    v.push_back(*it);
    ++it;
  }

  S.erase(it_start, it);


  if (v.size() == 0) {
    addv(1, 0, off, l, r);
  } else {
    if (l < v[0].first) {
      addv(1, 0, off, l, v[0].first);
    }
    for (int i = 0; i+1 < (int)v.size(); ++i) {
      addv(1, 0, off, v[i].second, v[i+1].first);
    }
    if (v.back().second < r) {
      addv(1, 0, off, v.back().second, r);
    }

    for (auto& p: v) {
      int il = max(l, p.first);
      int ir = min(r, p.second);
      mulv(1, 0, off, il, ir);
    }
  }

  int nl = l, nr = r;
  if (v.size()) {
    nl = min(nl, v[0].first);
    nr = max(nr, v.back().second);
  }

  S.insert({nl, nr});
}

int main(void) {
  int N, Q;
  scanf("%d %d", &N, &Q);

  REP(i, 2*off) P[i] = 1;

  while (Q--) {
    int type = IO::read_int();
    if (type == 1) {
      int l, r, x;
      l = IO::read_int();
      r = IO::read_int();
      x = IO::read_int();
      --l;

      query_add(l, r, x);
    } else {
      int l, r;
      l = IO::read_int();
      r = IO::read_int();
      --l;
      printf("%d\n", sum(1, 0, off, l, r));
    }
  }
  return 0;
}