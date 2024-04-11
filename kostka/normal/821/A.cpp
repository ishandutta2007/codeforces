//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int x[n][n];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> x[i][j];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    {
      bool ok = (x[i][j] == 1);
      for(int k=0; k<n; k++)
        for(int l=0; l<n; l++)
          if(x[i][k] + x[l][j] == x[i][j])
            ok = true;
      if(!ok)
      {
        puts("No");
        exit(0);
      }
    }
  puts("Yes");
  return 0;
}