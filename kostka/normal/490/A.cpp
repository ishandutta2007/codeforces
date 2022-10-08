#include "bits/stdc++.h"

using namespace std;

vector <int> X[4];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    int a;
    scanf("%d", &a);
    X[a].push_back(i+1);
  }
  int w = min(X[1].size(), min(X[2].size(), X[3].size()));
  printf("%d\n", w);
  for(int i=0; i<w; i++)
    printf("%d %d %d\n", X[1][i], X[2][i], X[3][i]);
  return 0;
}