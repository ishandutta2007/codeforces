//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  vector <vector <int> > X(a);
  for(int i=0; i<(int)X.size(); i++)
    X[i].resize(b);
  if(n > a*b)
  {
    puts("-1");
    return 0;
  }
  int nr1 = 1, nr2 = 2;
  for(int i=0; i<a; i++)
    for(int j=0; j<b; j++)
    {
      if((i+j)%2 == 0 and nr1 <= n)
      {
        X[i][j] = nr1;
        nr1 += 2;
      }
      if((i+j)%2 == 1 and nr2 <= n)
      {
        X[i][j] = nr2;
        nr2 += 2;
      }
    }
  for(int i=0; i<a; i++)
  {
    for(int j=0; j<b; j++)
      cout << X[i][j] << " ";
    cout << "\n";
  }
  return 0;
}