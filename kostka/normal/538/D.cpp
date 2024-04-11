//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <pair <int, int>> W;
string c[57];
string e[57];
vector <string> res;

int n;

bool onboard(int a, int b)
{
  return 0 <= a and a < n and 0 <= b and b < n;
}

bool check()
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    {
      if(c[i][j]=='.' and e[i][j]=='x')
        return false;
      if(c[i][j]=='x' and e[i][j]=='.')
        return false;
    }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> c[i];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(c[i][j]=='o')
        W.push_back({i,j});
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      e[i] += '.';
  for(int i=-n+1; i<=n-1; i++)
  {
    string w = "";
    for(int j=-n+1; j<=n-1; j++)
    {
      if(i==0 and j==0)
      {
        w += 'o';
        continue;
      }
      bool x = false;
      bool o = false;
      bool k = false;
      for(auto ele : W)
      {
        int xx, yy;
        tie(xx,yy) = ele;
        if(onboard(xx+i, yy+j))
        {
          if(c[xx+i][yy+j]=='o')
            o = true;
          if(c[xx+i][yy+j]=='x')
            x = true;
          if(c[xx+i][yy+j]=='.')
            k = true;
        }
      }
      if(k)
        w += '.';
      else
      {
        for(auto ele : W)
        {
          int xx, yy;
          tie(xx,yy) = ele;
          if(onboard(xx+i, yy+j))
            e[xx+i][yy+j] = 'x';
        }
        w += 'x';
      }
    }
    res.push_back(w);
  }
  if(check())
  {
    cout << "YES\n";
    for(auto ele : res)
      cout << ele << "\n";
  }
  else
    cout << "NO\n";
}