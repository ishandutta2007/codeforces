//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
int tab[MAXN];

int main()
{
  int n, w;
  cin >> n >> w;
  for(int i=0; i<2*n; i++)
    cin >> tab[i];
  sort(tab, tab + 2*n);
  int a = tab[0];
  int b = min(tab[n], 2*tab[0]);
  double res = b/2.0*n + b*n;
  cout << setprecision(40) << min((double)w, res) << "\n";
  return 0;
}