//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

map <long long, int> B, E;
const int MAXN = 1000*200+7;
long long tab[MAXN];

int main()
{
  int n, k;
  cin >> n >> k;
  for(int i=0; i<n; i++)
    cin >> tab[i];
  for(int i=0; i<n; i++)
    E[tab[i]]++;
  long long res = 0;
  for(int i=0; i<n; i++)
  {
    E[tab[i]]--;
    long long b = tab[i];
    if(b % k == 0)
    {
      long long a = b/k;
      long long c = b*k;
      res += 1LL * B[a] * E[c];
      //cout << B.count(a) << " " << E.count(c) << "\n";
    }
    //cout << res << "\n";
    B[tab[i]]++;
  }
  cout << res << "\n";
  return 0;
}