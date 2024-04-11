//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <int> f(n);
  for(int i=0; i<n; i++)
  {
    cin >> f[i];
    f[i]--;
  }
  map <int, int> h_inv;
  vector <int> g, h;
  for(int i=0; i<n; i++)
  {
      if(h_inv.find(f[i]) == h_inv.end())
      {
        h_inv[f[i]] = h_inv.size()-1;
        h.push_back(f[i]);
      }
      g.push_back(h_inv[f[i]]);
  }
  for(int i=0; i<n; i++)
    if(h[g[i]] != f[i])
    {
      puts("-1");
      return 0;
    }
  int m = h.size();
  for(int i=0; i<m; i++)
    if(g[h[i]] != i)
    {
      puts("-1");
      return 0;
    }
  cout << m << "\n";
  for(auto ele : g)
    cout << ele+1 << " ";
  cout << "\n";
  for(auto ele : h)
    cout << ele+1 << " ";
  cout << "\n";
  return 0;
}