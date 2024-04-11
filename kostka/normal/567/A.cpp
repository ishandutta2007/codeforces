//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100*1000+7;
int tab[MAXN];

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> tab[i];
  cout << tab[1]-tab[0] << " " << tab[n-1]-tab[0] << "\n";
  for(int i=1; i<n-1; i++)
    cout << min(tab[i+1]-tab[i], tab[i]-tab[i-1]) << " " << max(tab[n-1]-tab[i], tab[i]-tab[0]) << "\n";
  cout << tab[n-1] - tab[n-2] << " " << tab[n-1] - tab[0] << "\n";
  return 0;
}