//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector <int> res(n+1);
  set <pair <int, int> > S;
  long long suma = 0;
  for(int i=1; i<=n+k; i++)
  {
    if(i <= n)
    {
      int x;
      cin >> x;
      S.insert({-x, i});
    }
    if(i > k)
    {
      auto it = *S.begin();
      S.erase(it);
      res[it.second] = i;
      suma += 1LL * (i-it.second) * (-it.first);
    }
  }
  cout << suma << "\n";
  for(int i=1; i<=n; i++)
    cout << res[i] << " ";
  return 0;
}