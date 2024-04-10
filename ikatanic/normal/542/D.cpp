#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1000010;

map<llint, vector<llint>> M;
llint f[MAX];
int id1[MAX], id2[MAX];

int main(void) {
  llint A;
  scanf("%lld", &A);
  
  vector<llint> D;
  for (int i = 1; llint(i)*i <= A; ++i)
    if (A % i == 0) {
      D.push_back(i);
      if (A/i != i) D.push_back(A/i);
    }

  sort(D.begin(), D.end());
  REP(i, (int)D.size()) {
    if (D[i] < MAX) id1[D[i]] = i; else
      id2[A/D[i]] = i;
  }

  auto get_id = [&] (llint x) {
    return x < MAX ? id1[x] : id2[A/x];
  };

  vector<int> p;
  for (llint d: D) {
    if (d <= 2) continue;

    llint x = d - 1;
    llint p = -1;
    for (llint j = 2; j*j <= x; ++j)
      if (x%j == 0) { p = j; break; }
    
    if (p == -1) p = x;
    
    int cnt = 0;
    while (x % p == 0) cnt++, x /= p;
    if (x == 1) M[p].push_back(d);
  }
  
  int k = D.size();
  f[get_id(A)] = 1;
  for (auto &pp: M) {
    llint p = pp.first;
    vector<llint> &va = pp.second;
    
    for (int i = 0; i < k; ++i)
      for (llint a: va)
        if (D[i] % a == 0)
          f[get_id(D[i]/a)] += f[i];
  }

  printf("%lld\n", f[get_id(1)]);
  return 0;
}