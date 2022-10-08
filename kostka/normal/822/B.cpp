//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  string x, y;
  cin >> x >> y;
  int res = 1e9;
  vector <int> T, R;
  for(int i=0; i<=m-n; i++)
  {
    R.clear();
    for(int j=0; j<n; j++)
      if(x[j] != y[i+j])
        R.push_back(j+1);
    if(res > (int)R.size())
    {
      T = R;
      res = min(res, (int)R.size());
    }
  }
  cout << (int)T.size() << "\n";
  for(auto t : T)
    cout << t << " ";
  cout << "\n";
  return 0;
}