//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  unordered_map <string, int> X;
  vector <string> E(n), res(n);
  for(int i=0; i<n; i++)
  {
    cin >> E[i];
    set <string> used;
    for(int j=0; j<9; j++)
    {
      for(int k=1; k<=min(8,9-j); k++)
      {
        string pod = E[i].substr(j,k);
        if(used.find(pod) == used.end())
        {
          used.insert(pod);
          X[pod]++;
        }
      }
    }
  }
  for(int i=0; i<n; i++)
  {
    for(int k=1; k<=8; k++)
      for(int j=0; j<=9-k; j++)
        if(res[i] == "")
        {
          string pod = E[i].substr(j,k);
          if(X[pod] == 1)
            res[i] = pod;
        }

  }
  for(int i=0; i<n; i++)
    if(res[i] == "")
      res[i] = E[i];
  for(int i=0; i<n; i++)
    cout << res[i] << "\n";
  return 0;
}