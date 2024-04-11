//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second

const int ST = 1000;
const int MAXN = 1000*1000+7;
pair <int, int> X[MAXN];
int P[MAXN];

bool cmpy(int a, int b)
{
  if(X[a].y != X[b].y)
    return X[a].y < X[b].y;
  return X[a].x < X[b].x;
}

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    X[i] = make_pair(a, b);
    P[i] = i;
  }
  vector <int> E[ST+7];
  for(int i=1; i<=n; i++)
    E[X[i].x / ST].push_back(P[i]);
  for(int i=0; i<=ST; i++)
  {
    sort(E[i].begin(), E[i].end(), cmpy);
    if(i%2)
      reverse(E[i].begin(), E[i].end());
  }
  for(int i=0; i<=ST; i++)
    for(auto ele : E[i])
      printf("%d ", ele);
  return 0;
}