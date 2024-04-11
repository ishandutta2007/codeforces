//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1048576;

map <int, int> M;
int tab[MAXN], ile[MAXN], nile[MAXN], mapgen;
int drz[2*MAXN];

void change(int k, int w)
{
  int g = MAXN + k;
  while(g)
  {
    drz[g] += w;
    g /= 2;
  }
  return;
}

int sum(int a, int b)
{
  a += MAXN;
  b += MAXN;
  int wynik = 0;
  while(b>a)
  {
    if(a%2)
      wynik += drz[a++];
    if(!(b%2))
      wynik += drz[b--];
    a /= 2;
    b /= 2;
  }
  if(a==b)
    wynik += drz[a];
  return wynik;
}

vector <int> X;

int main()
{
    int n;
    scanf("%d", &n);
    long long res = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &tab[i]);
        if(M[tab[i]]==0)
            M[tab[i]] = ++mapgen;
        ile[M[tab[i]]]++;
        X.push_back(ile[M[tab[i]]]);
        change(ile[M[tab[i]]], 1);
    }
    for(int i=n-1; i>=0; i--)
    {
        nile[M[tab[i]]]++;
        change(X[i], -1);
        res += sum(nile[M[tab[i]]]+1,MAXN-7);
    }
    printf("%lld\n", res);
    return 0;
}