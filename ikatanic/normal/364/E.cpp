#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 2505;

set<int> C[MAXN]; // C[col] -> retci u kojima se pojavljuje u stupcu 1
vector<int> p[MAXN]; // p[x] -> stupci u kojima se pojavulje 1 u retku x

char a[MAXN][MAXN];
int h[MAXN];

llint inc(set<int> :: iterator it, set<int> &S, int k) {
  int row = *it;
  if (h[row] > k) return 0;

  int sumLeft = h[row];
  auto itl = it; --itl;
  while (itl != S.begin() && sumLeft+h[*itl] <= k) sumLeft += h[*(itl--)];
  
  auto itr = it, itr2 = it;
  auto prevl = itl;
  auto prevr = itr;
  auto prevr2 = itr2;
  ++itl, ++itr, ++itr2;
  
  llint ans = 0;
  int sum = sumLeft, sum2 = sumLeft+1;
  while (1) {
    while (sum + h[*itr] <= k) prevr = itr, sum += h[*(itr++)];
    while (sum2 + h[*itr2] <= k) prevr2 = itr2, sum2 += h[*(itr2++)];
    if (sum == k) ans -= (*itl - *prevl)*(*itr - *prevr);
    if (sum2 == k) ans += (*itl - *prevl)*(*itr2 - *prevr2);
    sum -= h[*itl], sum2 -= h[*itl];
    if (itl == it) break;
    prevl = itl, itl++;
  }
  h[row]++;
  return ans;
}


int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  //  srand(time(0));
  //  REP(i, n) REP(j, m)
  //    a[i][j] = '0' + (rand()%2);
  REP(i, n) scanf("%s", a[i]);
  
  llint ans = 0;
  for (int l = m-1; l >= 0; --l) {
    REP(i, n)
      if (a[i][l] == '1') {
        p[i].push_back(l);
        C[l].insert(i);
        if ((int)p[i].size() > k+1) C[ p[i][p[i].size()-k-2] ].erase(i);
      }

    static set<int> S;
    S.clear();
    S.insert(-1);
    S.insert(n);
    
    REP(i, n) h[i] = 0;
    h[n] = k+1;
    auto it = S.end();

    llint sum = 0;
    if (k == 0) sum = n*(n+1)/2;

    for (int r = l; r < m; ++r) {
      for (int row: C[r]) {
        tie(it, ignore) = S.insert(row);
        sum += inc(it, S, k);
      }
      ans += sum;
    }
  }
  cout << ans << endl;
  return 0;
}