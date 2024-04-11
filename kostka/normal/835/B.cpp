//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int k;
  cin >> k;
  string x;
  cin >> x;
  int n = x.size();
  sort(x.begin(), x.end());
  int sum = 0;
  for(int i=0; i<n; i++)
    sum += x[i]-'0';
  for(int i=0; i<=n; i++)
  {
    if(sum >= k)
    {
      cout << i << "\n";
      break;
    }
    sum -= x[i]-'0';
    sum += 9;
  }
  return 0;
}