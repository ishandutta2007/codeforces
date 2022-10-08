#include "bits/stdc++.h"

using namespace std;

const int MAXN = 30007;
int a[MAXN];
bool ok[MAXN];

int main()
{
  int n, t;
  scanf("%d%d", &n, &t);
  for(int i=1; i<n; i++)
    scanf("%d", a+i);
  ok[1] = true;
  for(int i=1; i<=n; i++)
    if(ok[i])
      ok[i+a[i]] = true;
  puts(ok[t] ? "YES" : "NO");
}