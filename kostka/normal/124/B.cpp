#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector <string> x(n);
  for(int i=0; i<n; i++)
    cin >> x[i];
  vector <int> tab(k);
  for(int i=0; i<k; i++)
    tab[i] = i;
  long long res = 1e15;
  do{
    vector <int> W;
    long long minl = 1e15, maxl = -1;
    for(int i=0; i<n; i++)
    {
      long long liczba = 0;
      for(int j=0; j<k; j++)
      {
        liczba *= 10;
        liczba += x[i][tab[j]] - '0';
      }
      minl = min(minl, liczba);
      maxl = max(maxl, liczba);
    }
    //sort(W.begin(), W.end());
    res = min(res, maxl-minl);
  }while(next_permutation(tab.begin(), tab.end()));
  cout << res << "\n";
  return 0;
}