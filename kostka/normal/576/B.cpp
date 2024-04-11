//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
int gdz[MAXN], p, q;
bool odw[MAXN], odw2[MAXN];

int dfs(int v)
{
  odw[v] = true;
  if(odw[gdz[v]] == false)
    return 1 + dfs(gdz[v]);
  return 1;
}

void dfs2(int v, int e=0)
{
  odw2[v] = true;
  if(v != p and v != q)
  {
    if(e%2)
      cout << p << " " << v << "\n";
    else
      cout << q << " " << v << "\n";
  }
  if(odw2[gdz[v]] == false)
    dfs2(gdz[v], e+1);
}


int main()
{
  int n;
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> gdz[i];
  for(int i=1; i<=n; i++)
    if(gdz[i] == i)
    {
      cout << "YES\n";
      for(int j=1; j<=n; j++)
        if(i != j)
          cout << i << " " << j << "\n";
      return 0;
    }
  vector <int> W;
  for(int i=1; i<=n; i++)
    if(odw[i] == false)
      W.push_back(dfs(i));
  sort(W.begin(), W.end());
  for(auto ele : W)
    cerr << ele << " ";
  bool ok = ((*W.begin()) == 2);
  for(auto ele : W)
    if(ele % 2)
      ok = false;
  if(ok)
  {
    puts("YES");
    for(int i=1; i<=n; i++)
    {
      if(i == gdz[gdz[i]])
      {
        p = i; q = gdz[i];
        cout << p << " " << q << "\n";
        for(int j=1; j<=n; j++)
          if(odw2[j] == false)
            dfs2(j);
        return 0;
      }
    }
  }
  else
    puts("NO");
  return 0;
}