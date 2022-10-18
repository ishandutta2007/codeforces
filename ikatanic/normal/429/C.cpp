#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int a[30];
int n;

bool done[30];
bool found;

void rec(int x, int cnt, int cur, int rem, int n0) {
  if (found) return;
  if (x == n) {
    if (n0 == 0) found = true;
    return;
  }  
  if (!done[x]) return;
  
  if (cur == n) {
    if (cnt+rem >= 2 && rem <= n0)
      rec(x+1, 0, x+2, a[x+1], n0 - rem);
    return;
  }
  
  if (a[cur]+1 <= rem && !done[cur]) {
    done[cur] = true;
    rec(x, cnt+1, cur+1, rem-a[cur]-1, n0);
    done[cur] = false;
    if (cnt == 0) return;
  }
  rec(x, cnt, cur+1, rem, n0);
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) { 
    scanf("%d", a+i);  
    --a[i];
  }
  sort(a, a + n, greater<int>());

  int n0 = 0;
  while (n-1-n0 >= 0 && a[n-1-n0] == 0) n0++;
  if (n0*2 < n) { puts("NO"); return 0; }
  
  if (n0 == n) {
    puts(n == 1 ? "YES" : "NO");
    return 0;
  }
  
  n -= n0;
  REP(i, n) done[i] = false;
  done[0] = true;

  rec(0, 0, 1, a[0], n0);
  if (found) puts("YES"); else
    puts("NO");
  
  return 0;
}