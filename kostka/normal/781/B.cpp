//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

set <string> USED;
unordered_map <string, int> E;

void fail()
{
  cout << "NO\n";
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <string> res(n);
  vector <pair <string, string> > M;
  for(int i=0; i<n; i++)
  {
    string x, y;
    cin >> x >> y;
    M.push_back(make_pair(x.substr(0,3),x.substr(0,2)+y.substr(0,1)));
    E[M.back().first] += 1;
  }
  for(int i=0; i<n; i++)
    if(E[M[i].first] > 1)
    {
      if(USED.find(M[i].second) != USED.end())
        fail();
      else
      {
        USED.insert(M[i].second);
        res[i] = M[i].second;
      }
    }
  bool change = true;
  while(change)
  {
    change = false;
    for(int i=0; i<n; i++)
    {
      if(res[i] == "" and E[M[i].first] == 1)
      {
        if(USED.find(M[i].first) != USED.end())
        {
          if(USED.find(M[i].second) != USED.end())
          {
            fail();
          }
          else
          {
            USED.insert(M[i].second);
            res[i] = M[i].second;
            change = true;
          }
        }
        else if(USED.find(M[i].second) != USED.end())
        {
          if(USED.find(M[i].first) != USED.end())
            fail();
          else
          {
            USED.insert(M[i].first);
            res[i] = M[i].first;
            change = true;
          }
        }
      }
    }
    if(!change)
    {
      for(int i=0; i<n; i++)
        if(res[i] == "")
        {
          USED.insert(M[i].first);
          res[i] = M[i].first;
          change = true;
        }
    }
  }
  cout << "YES\n";
  for(auto ele : res)
    cout << ele << "\n";
  return 0;
}