#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1000100;
const int B = 1225;
const int K = MAX/B + 1;

int x[MAX], y[MAX];
vector<int> v[K];

int main(void) {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d %d", x+i, y+i);
    v[x[i]/B].push_back(i);
  }

  REP(i, K) {
    sort(v[i].begin(), v[i].end(), [&] (const int& a, const int& b) {
        return y[a] < y[b];
      }
    );

    if (i%2) reverse(v[i].begin(), v[i].end());
    for (int j: v[i]) printf("%d ", j+1);
  }
  printf("\n");
  return 0;
}