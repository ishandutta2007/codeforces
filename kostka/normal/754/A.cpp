//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector <int> x(n);
  bool ok = false;
  int sum = 0;
  for(int i=0; i<n; i++)
  {
    cin >> x[i];
    sum += x[i];
    if(x[i] != 0)
      ok = true;
  }
  if(!ok)
  {
    cout << "NO\n";
    return 0;
  }
  else
  {
    if(sum != 0)
    {
      cout << "YES\n1\n1 " << n << "\n";
      return 0;
    }
    int left = 0;
    for(int i=0; i<n; i++)
    {
      left += x[i];
      int right = sum - left;
      if(left and right)
      {
        cout << "YES\n2\n1 " << i+1 << "\n" << i+2 << " " << n << "\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}