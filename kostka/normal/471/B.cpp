#include "bits/stdc++.h"

using namespace std;

const int MAXN = 2007;
vector <pair<int,int> > X;

void check()
{
  int n = (int)X.size(), prev = -1;
  for(int i=1; i<n; i++)
  {
    int ile = 1;
    while(i<n && X[i].first == X[i-1].first)
    {
      ile++;
      i++; 
    }
    if(ile>=3)
    {
      puts("YES");
      for(int k=0; k<i-3; k++)
        printf("%d ", X[k].second);
      printf("%d %d %d ", X[i-3].second, X[i-2].second, X[i-1].second);
      for(int k=i; k<n; k++)
        printf("%d ", X[k].second);
      printf("\n");
      for(int k=0; k<i-3; k++)
        printf("%d ", X[k].second);
      printf("%d %d %d ", X[i-2].second, X[i-3].second, X[i-1].second);
      for(int k=i; k<n; k++)
        printf("%d ", X[k].second);
      printf("\n");
      for(int k=0; k<i-3; k++)
        printf("%d ", X[k].second);
      printf("%d %d %d ", X[i-3].second, X[i-1].second, X[i-2].second);
      for(int k=i; k<n; k++)
        printf("%d ", X[k].second);
      printf("\n");
      return;
    }
    else if(ile==2)
    {
      if(prev==-1)
        prev = i;
      else
      {
        puts("YES");
        for(int k=0; k<n; k++)
          printf("%d ", X[k].second);
        printf("\n");
        swap(X[prev-1], X[prev-2]);
        for(int k=0; k<n; k++)
          printf("%d ", X[k].second);
        printf("\n");
        swap(X[i-1], X[i-2]);
        for(int k=0; k<n; k++)
          printf("%d ", X[k].second);
        printf("\n");
        return;
      }
    }
  }
  puts("NO");
}

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
  {
    int a;
    scanf("%d", &a); 
    X.push_back(make_pair(a,i));
  }
  sort(X.begin(), X.end());
  check();
  return 0;
}