//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <int> X(n);
  map <int, int> M;
  for(int i=0; i<n; i++)
    cin >> X[i];
  auto Y = X;
  sort(Y.begin(), Y.end());
  for(int i=0; i<n; i++)
    M[Y[i]] = i;
  for(int i=0; i<n; i++)
    Y[i] = M[X[i]];
  vector <bool> vis(n);
  vector <vector <int> > res;
  for(int i=0; i<n; i++)
    if(!vis[i])
    {
      vector <int> e;
      int d = i;
      vis[d] = true;
      while(!vis[Y[d]])
      {
        e.push_back(d);
        d = Y[d];
        vis[d] = true;
      }
      e.push_back(d);
      res.push_back(e);
    }
  cout << res.size() << "\n";
  for(auto& r : res)
  {
    cout << r.size() << " ";
    for(auto& rr : r)
      cout << rr+1 << " ";
    cout << "\n";
  }
  return 0;
}