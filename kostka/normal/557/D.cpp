//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
vector <int> G[MAXN];
int col[MAXN], p, q;

void dfs(int v, int c)
{
  col[v] = c;
  if(c==1) p++;
  else     q++;
  for(auto w : G[v])
  {
    if(col[w]==c)
    {
      cout << 0 << " " << 1 << "\n";
      exit(0);
    }
    if(col[w]==0)
      dfs(w, 3-c);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  // trzy
  if(m==0)
  {
    cout << 3 << " " << 1LL*n*(n-1)*(n-2)/6 << "\n";
    return 0;
  }
  // zero
  vector <pair <int, int>> S;
  for(int i=1; i<=n; i++)
    if(col[i]==0)
    {
      p = 0; q = 0;
      dfs(i,2);
      S.push_back({p,q});
    }
  // jeden
  long long res = 0;
  for(auto ele : S)
  {
    p = ele.first;
    q = ele.second;
    res += 1LL*p*(p-1);
    res += 1LL*q*(q-1);
  }
  if(res)
  {
    cout << 1 << " " << res/2 << "\n";
    return 0;
  }
  // dwa
  cout << 2 << " " << 1LL*m*(n-2) << "\n";
  return 0;
}