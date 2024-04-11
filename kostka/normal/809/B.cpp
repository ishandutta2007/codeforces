//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
vector <int> tab;
int n, k;

int odl(int a)
{
  auto it = lower_bound(tab.begin(), tab.end(), a);
  int odla = 1e9;
  if(it != tab.end())
  {
    odla = min(odla, (*it)-a);
  }
  if(it != tab.begin())
  {
    it--;
    odla = min(odla, a-(*it));
  }
  return odla;
}

bool check(int a, int b)
{
  assert(1 <= a and a <= n and 1 <= b and b <= n);
  //cerr << a << " " << b << " " << " " << odl(a) << " " << odl(b) << " " << (odl(a) <= odl(b)) << "\n";
  cout << 1 << " " << a << " " << b << "\n";
  fflush(stdout);
  string x;
  cin >> x;
  return (x == "TAK");
  //return odl(a) <= odl(b);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  //tab.resize(k);
  //for(int i=0; i<k; i++)
  //  cin >> tab[i];
  int a = 0, b = n;
  while(b - a > 1)
  {
    int m = (a+b)/2;
    if(check(m, m+1))
      b = m;
    else
      a = m;
  }
  int c = b, d = n;
  while(d - c > 1)
  {
    int m = (c+d)/2;
    if(not(check(m+1, m)))
      d = m;
    else
      c = m;
  }
  if(!check(d,b))
  {
    c = 0, d = b-1;
    while(d - c > 1)
    {
      int m = (c+d)/2;
      if(not(check(m+1, m)))
        d = m;
      else
        c = m;
    }
  }
  cout << 2 << " " << b << " " << d << "\n";
  fflush(stdout);
  return 0;
}