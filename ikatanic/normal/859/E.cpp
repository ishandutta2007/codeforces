#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int a[MAX], b[MAX];
int who[MAX];
bool bio[MAX];

vector<int> E[MAX];

int dfs(int x) {
  int ret = 1;
  bio[x] = true;
  for (int y: E[x]) {
    ret += dfs(y);
  }
  return ret;
}

bool dfs2(int x) {
  if (bio[x]) return false;
  bool ret = false;
  bio[x] = true;
  for (int y: E[x]) ret |= dfs2(y);
  ret |= dfs2(b[who[x]]);
  ret |= b[who[x]] == x;
  return ret;
}

int main(void) {
  int N;
  scanf("%d", &N);
  REP(i, 2*N) who[i] = -1;
  REP(i, N) {
    scanf("%d %d", &a[i], &b[i]);
    --a[i], --b[i];
    who[a[i]] = i;

    E[b[i]].push_back(a[i]);
  }

  int ret = 1;
  REP(i, 2*N) {
    if (who[i] == -1) {
      ret = mul(ret, dfs(i));
    }
  }

  REP(i, 2*N) {
    if (who[i] != -1 && !bio[i]) {
      if (!dfs2(i)) {
        ret = mul(ret, 2);
      }
    }
  }

  printf("%d\n", ret);
  return 0;
}