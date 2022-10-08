#include "bits/stdc++.h"

using namespace std;

map<int,int> tab, pab;
map<int,int> czy;
vector <int> X, Y;

set <int> S;

int main()
{
  int n;
  scanf("%d", &n);

  {
    for(int i=0; i<n; i++)
    {
      int a, b;
      scanf("%d%d", &a, &b);
      tab[a] = b;
      pab[b] = a;
      S.insert(a);
      czy[a] += 1;
      czy[b] -= 1;
    }
    int ax = 0;
    while(true)
    {
      if(tab[ax]==0)
        break;
      X.push_back(tab[ax]);
      ax = tab[ax];
    }
    if(n%2==0)
    {
      int bx = 0;
      while(true)
      {
        if(pab[bx]==0)
          break;
        Y.push_back(pab[bx]);
        bx = pab[bx];
      }
      reverse(Y.begin(), Y.end());
    }
    else
    {
      int bx;
      for(set<int>::iterator it = S.begin(); it != S.end(); it++)
      {
        int ele = (*(it));
        if(czy[ele]==1)
          bx = ele;
      }
      Y.push_back(bx);
      while(true)
      {
        if(tab[bx]==0)
          break;
        //cerr << "B" << bx << " " << tab[bx] << "\n";
        Y.push_back(tab[bx]);
        bx = tab[bx];
      }
    }
    int a = min(X.size(), Y.size());
    for(int i=0; i<a; i++)
      printf("%d %d ", Y[i], X[i]);
    if(Y.size() > a)
      printf("%d ", Y.back());
  }
  return 0;
}