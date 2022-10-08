//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

bool por(vector <int> &A, int p, int m, int dl)
{
  for(int i=0; i<dl; i++)
  {
    if(A[p+i] > A[m+i])
      return false;
    if(A[p+i] < A[m+i])
      return true;
  }
  return false;
}

void split(vector <int> &A, int p, int k)
{
  if((k-p)%2)
    return;
  int m = (p+k)/2;
  split(A, p, m);
  split(A, m, k);
  int dl = k-m;
  if(por(A,p,m,dl))
    for(int i=0; i<dl; i++)
      swap(A[i+p], A[i+m]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  string x, y;
  cin >> x >> y;
  vector <int> X, Y;
  for(int i=0; i<(int)x.size(); i++)
    X.push_back(x[i]);
  for(int i=0; i<(int)y.size(); i++)
    Y.push_back(y[i]);
  split(X,0,(int)X.size());
  split(Y,0,(int)Y.size());
  puts(X == Y ? "YES" : "NO");
  return 0;
}