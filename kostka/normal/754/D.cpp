//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector <pair <int, int> > W(n+1);
  vector <int> E;
  for(int i=1; i<=n; i++)
  {
    cin >> W[i].first >> W[i].second;
    E.push_back(i);
    E.push_back(-i);
  }
  sort(E.begin(), E.end(), [&](const int &a, const int &b){
    int left = a > 0 ? W[abs(a)].first : W[abs(a)].second;
    int right = b > 0 ? W[abs(b)].first : W[abs(b)].second;
    if(left != right)
      return left < right;
    else
      return a > b;
  });
  set <int> S, RES;
  for(int i=1; i<=k; i++)
    RES.insert(i);
  set <pair <int, int> > M;
  int maks = 0, left = -1, right = -1;
  for(auto e : E)
  {
    int now = e > 0 ? W[abs(e)].first : W[abs(e)].second;
    if(e > 0)
    {
      S.insert(e);
      M.insert(make_pair(W[e].second, e));
    }
    else
    {
      e *= -1;
      if(S.find(e) != S.end())
      {
        S.erase(e);
        M.erase(make_pair(W[e].second, e));
      }
    }
    if((int)S.size() > k)
    {
      auto it = M.begin();
      int nr = (*it).second;
      S.erase(nr);
      M.erase(make_pair(W[nr].second, nr));
    }
    if((int)S.size() == k)
    {
      int res = (*M.begin()).first - now + 1;
      if(maks < res)
      {
        maks = res;
        left = now;
        right = (*M.begin()).first;
      }
    }
  }
  cout << maks << "\n";
  if(maks != 0)
  {
    RES.clear();
    for(int i=1; i<=n; i++)
    {
      if(W[i].first <= left and W[i].second >= right)
        RES.insert(i);
      if((int)RES.size() == k)
        break;
    }
  }
  for(auto ele : RES)
    cout << ele << " ";
  cout << "\n";
  return 0;
}