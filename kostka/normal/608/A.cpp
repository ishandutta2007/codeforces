//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int tab[1007];

int main()
{
  int n, k;
  cin >> n >> k;
  for(int i=0; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    tab[a] = max(tab[a], b);
  }
  for(int i=k; i>=0; i--)
    tab[i-1] = max(tab[i]+1, tab[i-1]);
  cout << tab[0] << "\n";
  return 0;
}