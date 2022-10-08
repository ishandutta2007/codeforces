// Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
int a[MAXN], tab[MAXN];

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  for(int i=0; i<n; i++)
    tab[a[i]] = tab[a[i]-1] + 1;
  int maks = 0;
  for(int i=0; i<n; i++)
    maks = max(tab[i+1], maks);
  cout << n -maks << "\n";
}