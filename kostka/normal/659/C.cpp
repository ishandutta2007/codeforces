//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

unordered_set <int> S;

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++)
  {
    int x;
    cin >> x;
    S.insert(x);
  }
  vector <int> R;
  for(int i=1; i<=m; i++)
  {
    if(S.find(i) == S.end())
    {
      if(i <= m)
      {
        R.push_back(i);
        m -= i;
      }
    }
  }
  cout << (int)R.size() << "\n";
  for(auto ele : R)
    cout << ele << " ";
  cout << "\n";
  return 0;
}