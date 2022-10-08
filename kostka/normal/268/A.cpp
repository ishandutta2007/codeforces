#include "bits/stdc++.h"

using namespace std;

int h[37], g[37];

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
      cin >> h[i] >> g[i];
  int wyn = 0;
  for(int i=0; i<n; i++)
      for(int j=i+1; j<n; j++)
      {
          if(h[i]==g[j])
              wyn++;
          if(g[i]==h[j])
              wyn++;
      }
  cout << wyn << "\n";
}