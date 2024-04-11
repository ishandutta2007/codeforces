//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int v1, v2;
  cin >> v1 >> v2;
  int t, d;
  cin >> t >> d;
  int tab1[t], tab2[t];
  tab1[0] = v1;
  for(int i=1; i<t; i++)
    tab1[i] = tab1[i-1] + d;
  tab2[t-1] = v2;
  for(int i=t-2; i>=0; i--)
    tab2[i] = tab2[i+1] + d;
  long long sum = 0;
  for(int i=0; i<t; i++)
    sum += min(tab1[i], tab2[i]);
  cout << sum << "\n";
  return 0;
}