#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;

vector<int> E[MAXN];
int a[MAXN], p[MAXN];
int dad[MAXN], sz[MAXN];
bool bio[MAXN];

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

void merge(int x, int y) {
  dad[y] = x;
  sz[x] += sz[y];
  sz[y] = 0;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d", a+i);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  REP(i, n) p[i] = i;
  sort(p, p + n, [] (const int &x, const int &y) {
      return a[x] > a[y];
    }
  );
  
  REP(i, n) dad[i] = i, sz[i] = 1;
  
  llint ans = 0;
  REP(i, n) {
    int x = p[i];

    set<int> S;
    for (int y: E[x])
      if (bio[y]) S.insert(findset(y));
    
    llint sum = 1;
    for (int y: S) {
      ans += sum*sz[y]*a[x];
      sum += sz[y];
      merge(y, findset(x));
    }
    bio[x] = true;
  }
  
  double a = ans*2.0 / (double(n)*(n-1));
  printf("%lf\n", a);
  return 0;
}