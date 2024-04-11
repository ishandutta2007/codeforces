#include "bits/stdc++.h"

using namespace std;

vector <long long> W;

int main()
{
  int n;
  cin >> n;
  long long r;
  cin >> r;
  vector <long long> dlug(n+1), limit(n+1);
  for(int i=1; i<=n; i++)
    cin >> dlug[i];
  for(int i=1; i<=n; i++)
    cin >> limit[i];
  for(int i=1; i<=n; i++)
    if(dlug[i] > limit[i])
    {
      cout << "-1\n";
      return 0;
    }
  long long sciezkaSoFar = 0;
  long long fuel = 0;
  long long wynik = 0;
  for(int i=1; i<=n; i++)
  {
    sciezkaSoFar += dlug[i-1];
    // jestem na turbo
    if(fuel > dlug[i])
    {
      fuel -= dlug[i];
      continue;
    }
    long long x = 2 * dlug[i] - fuel - limit[i];
    //cerr << x << "\n";
    if(x <= 0)
    {
      fuel = 0;
      continue;
    }
    wynik += x/r;
    for(int j=0; j < x/r and (int)W.size() < 100000; j++)
      W.push_back(sciezkaSoFar + fuel + 1LL * j * r);
    if(x % r)
    {
      wynik++;
      if((int)W.size() < 1000000)
        W.push_back(sciezkaSoFar + dlug[i] - x % r);
    }
    fuel = r - x % r;
    if(fuel == r)
      fuel -= r;
  }
  cout << wynik << "\n";
  if(wynik <= 100000)
  {
    for(int i=0; i<(int)W.size(); i++)
      cout << 2*W[i]-1LL*i*r << " ";
    cout << "\n";
  }
}