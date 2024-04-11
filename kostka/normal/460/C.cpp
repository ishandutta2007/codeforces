//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int tmp;

const int MAXN = 131072;
int tab[MAXN], ilee[MAXN], drz[2*MAXN];

int find(int k)
{
  int g = MAXN + k;
  int res = 0;
  while(g)
  {
    res += drz[g];
    g /= 2;
  }
  return res;
}

void sum(int a, int b, int ile)
{
  a += MAXN;
  b += MAXN;
  while(b>a)
  {
    if(a%2)
      drz[a++] += ile;
    if(!(b%2))
      drz[b--] += ile;
    a /= 2;
    b /= 2;
  }
  if(a==b)
    drz[a] += ile;
  return;
}

vector <pair <int, int> > E;

bool check(int a, int n, int m, int w)
{
    for(int i=0; i<n; i++)
        ilee[i] = max(0,a-tab[i]);
    int used = 0;
    for(int i=0; i<n; i++)
    {
        int brak = ilee[i] - find(i);
        if(brak > 0)
        {
            used += brak;
            E.push_back(make_pair(i,brak));
            sum(i,i+w-1, brak);
        }
        if(used > m)
            return false;
    }
    return true;
}

void clean(int w)
{
    for(auto pair : E)
         sum(pair.first,pair.first+w-1, -pair.second);
    E.clear();
}

int main()
{
    int n, m, w;
    scanf("%d%d%d", &n, &m, &w);
    for(int i=0; i<n; i++)
        scanf("%d", tab+i);
    int mini = 2*1000*1000*1000;
    for(int i=0; i<n; i++)
    {
        mini = min(mini, tab[i]);
    }
    int p = mini, k = mini + m + 7;
    while(p<k-1)
    {
        int s = (p+k)/2;
        if(check(s,n,m,w))
            p = s;
        else
            k = s;
        clean(w);
    }
    printf("%d\n", p);
    return 0;
}