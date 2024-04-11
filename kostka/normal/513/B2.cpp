#include "bits/stdc++.h"

using namespace std;

deque <int> Q;

  int n;

void go(int k, long long a, long long b)
{
  if(n==k)
    return;
  if(a < b/2)
  {
    go(k+1,a,b/2);
    Q.push_front(k+1);
  } 
  else
  {
    go(k+1,a-b/2,b/2);
    Q.push_back(k+1);
  }
}

int main()
{
  long long m;
  scanf("%d%I64d", &n, &m);
  long long ile = 1LL<<(n-1);
  go(0,m-1,ile);
  for(int i=0; i<(int)Q.size(); i++)
    printf("%d ", Q[i]);
}