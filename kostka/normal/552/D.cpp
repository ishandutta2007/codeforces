//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

struct point
{
  int x, y;
};

point tab[2007];

pair <int, int> angle(int p, int q)
{
  int ex = tab[q].x - tab[p].x, ey = tab[q].y - tab[p].y;
  int d = __gcd(abs(ex),abs(ey));
  if(ex < 0 or (ex==0 and ey<0))
    d *= -1;
  return make_pair(ex/d, ey/d);
}

int main()
{
  long long n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> tab[i].x >> tab[i].y;
  long long res = n * (n-1) * (n-2) / 6;
  for(int i=0; i<n; i++)
  {
    map <pair <int, int>, int> M;
    for(int j=i+1; j<n; j++)
        M[angle(i,j)] += 1;
    for(auto ele : M)
    {
      long long e = ele.second;
      res -= e * (e-1) / 2;
    }
  }
  cout << res << "\n";
  return 0;
}