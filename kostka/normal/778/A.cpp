//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
int a[MAXN];
bool usu[MAXN];
string x, y;

bool check(int m)
{
  for(int i=0; i<(int)x.size(); i++)
    usu[a[i]] = (i < m);
  int wsk = 0;
  for(int i=0; i<(int)x.size(); i++)
    if(!usu[i])
      if(wsk < (int)y.size() and x[i] == y[wsk])
        wsk++;
  return wsk == (int)y.size();
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> x >> y;
  int n = (int)x.size();
  for(int i=0; i<n; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  int l = 0, r = n;
  while(r - l > 1)
  {
    int m = (l+r)/2;
    if(check(m))
      l = m;
    else
      r = m;
  }
  cout << l << "\n";
  return 0;
}