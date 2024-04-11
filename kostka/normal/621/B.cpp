#include "bits/stdc++.h"

using namespace std;

map<int, int> L, M;

int main()
{
  int n;
  cin >> n;
  while(n--)
  {
    int a, b;
    cin >> a >> b;
    M[a+b]++;
    L[a-b]++;
  }

  long long res = 0;

  for(map<int,int>::iterator it = L.begin(); it != L.end(); it++)
    res += 1LL*((*it).second)*((*it).second-1);

  for(map<int,int>::iterator it = M.begin(); it != M.end(); it++)
    res += 1LL*((*it).second)*((*it).second-1);

  cout << res/2 << "\n";
}