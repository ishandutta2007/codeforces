#include "bits/stdc++.h"

using namespace std;

const int MAXN = 507;
const int MAXM = 1007;
set <int> S;
vector <int> V[2];
int w[MAXN], u[MAXM];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++)
    scanf("%d", w+i);
  for(int i=0; i<m; i++)
  {
    scanf("%d", u+i);
    if(S.find(u[i]) == S.end())
    {
      S.insert(u[i]);
      V[0].push_back(u[i]);
    }
  }
  long long waga = 0;
  for(int i=0; i<m; i++)
  {
    V[(i+1)%2].clear();
    V[(i+1)%2].push_back(u[i]);
    for(int j=0; j<(int)V[i%2].size(); j++)
    {
      if(V[i%2][j]!=u[i])
      {
         waga += w[V[i%2][j]];
         //cerr << V[i%2][j];
      }
      else
         break;
    }
    //cerr << "\n";
    for(int j=0; j<(int)V[i%2].size(); j++)
      if(V[i%2][j]!=u[i])
        V[(i+1)%2].push_back(V[i%2][j]);
    //for(int j=0; j<(int)V[i%2].size(); j++)
    //  cerr << V[i%2][j] << " ";
    //cerr << "\n";
  }
  printf("%I64d\n", waga);
  return 0; 
}