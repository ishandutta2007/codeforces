#include "bits/stdc++.h"

using namespace std;

const int MAXN = 307;
char buf[MAXN];
int pos[MAXN], co[MAXN];
vector <int> G[MAXN];
bool ok[MAXN];

void dfs(int v)
{
  ok[v] = 1;
  for(auto w : G[v])
    if(ok[w] == false)
      dfs(w);
}


int main()
{
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
  {
     int a;
     scanf("%d", &a);
     pos[a] = i;
     co[i] = a;
  }
  for(int i=1; i<=n; i++)
  {
    scanf("%s", buf);
    for(int j=1; j<=n; j++)
      if(buf[j-1]=='1')
        G[i].push_back(j);
  }
  for(int i=1; i<=n; i++)
  {
    //cerr << pos[i] << "\n";
    for(int j=1; j<=n; j++)
      ok[j] = false;
    dfs(pos[i]);
    //for(int j=1; j<=n; j++)
    //  cerr << ok[j] << " ";
    //cerr << "\n";
    for(int j=1; j<pos[i]; j++)
      if(ok[j]==true and i<co[j])
      {
        int tmp = pos[i];
        pos[i] = j;
        pos[co[j]] = tmp;
        int tmx = co[j];
        co[j] = i;
        co[tmp] = tmx;
        break;
      }
    //for(int j=1; j<=n; j++)
    //  printf("%d ", co[j]);
    //printf("\n");
  }
  for(int i=1; i<=n; i++)
    printf("%d ", co[i]);
  return 0;
}