#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
int a[MAXN], b[MAXN];

long long res = -1LL<<60;
int r = 0, s = 0;

void check(int x, int n, int m)
{
  int w2 = a + n - lower_bound(a, a+n, x);
  int w3 = n - w2;
  int u2 = b + m - lower_bound(b, b+m, x);
  int u3 = m - u2;
  int w = w2*3+w3*2, u = u2*3+u3*2;
  if(w-u > res)
  {
    res = w-u;
    r = w;
    s = u;
  }
  return;
}

int main()
{
  int n, m;
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", a+i);
  scanf("%d", &m);
  for(int i=0; i<m; i++)
    scanf("%d", b+i);
  sort(a, a+n);
  sort(b, b+m);
  set <int> S;
  for(int i=0; i<n; i++)
  {
    S.insert(a[i]);
    S.insert(a[i]-1);
    S.insert(a[i]+1);
  }
  for(int i=0; i<m; i++)
  {
    S.insert(b[i]);
    S.insert(b[i]-1);
    S.insert(b[i]+1);
  }
  for(auto ele : S)
    check(ele,n,m);
  printf("%d:%d", r, s);
}