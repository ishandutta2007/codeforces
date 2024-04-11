#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
int tab[MAXN];

int main()
{
  string x;
  cin >> x;
  int n = x.size();
  int naw = 0, ile = 0, lastx = -1;
  for(int i=0; i<n; i++)
  {
    if(x[i]=='(')
    {
      naw++;
      tab[i] = 1;
    }
    if(x[i]==')')
    {
      naw--;
      tab[i] = -1;
    }
    if(x[i]=='#')
    {
      ile++;
      naw--;
      tab[i] = -1;
      lastx = max(lastx, i);
    }
  }
  if(lastx != -1)
  {
    if(naw < 0)
    {
      puts("-1");
      return 0;
    }
    tab[lastx] -= naw;
  }
  int rrr = 0;
  for(int i=0; i<n; i++)
  {
    //cerr << tab[i] << " ";
    rrr += tab[i];
    if(rrr < 0)
    {
      puts("-1");
      return 0;
    }
  }
  for(int i=0; i<n; i++)
    if(x[i]=='#')
      cout << -tab[i] << "\n";
  return 0;
}