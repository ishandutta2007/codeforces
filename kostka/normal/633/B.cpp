//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAX = 1000000;
int zero[MAX+7];

int main()
{
  int n;
  cin >> n;
  int e = 5, ile = 1;
  while(e <= MAX)
  {
    for(int k=e; k <= MAX; k += e)
      zero[k] += ile;
    e *= 5;
  }
  int wynik = 0;
  for(int i=1; i<=MAX; i++)
  {
    zero[i] += zero[i-1];
    if(zero[i] == n)
      wynik++;
  }
  cout << wynik << "\n";
  for(int i=1; i<=MAX; i++)
  {
    if(zero[i] == n)
      cout << i << " ";
  }
  return 0;
}