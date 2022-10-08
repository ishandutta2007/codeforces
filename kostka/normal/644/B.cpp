//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;



int main()
{
  int n, si;
  cin >> n >> si;
  vector <pair <int, int> > Z;
  for(int i=0; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    Z.emplace_back(a,b);
  }
  queue <int> Q;
  long long czas = 0;
  vector <long long> odp(n);
  for(int i=0; i<n; i++)
  {
    //cerr << czas << " " << Z[i].first << "\n";
    while(!Q.empty())
    {
      int v = Q.front();
      if(czas <= Z[i].first)
      {
        Q.pop();
        czas = max(czas,(long long)Z[v].first) + Z[v].second;
        odp[v] = czas;
      }
      else
        break;
    }
    if(czas <= Z[i].first)
    {
      czas = max(czas, (long long)Z[i].first) + Z[i].second;
      odp[i] = czas;
    }
    if(odp[i] == 0)
    {
      if(si > (int)Q.size())
        Q.push(i);
      else
        odp[i] = -1;
    }
    while(!Q.empty())
    {
      int v = Q.front();
      if(czas <= Z[i].first)
      {
        Q.pop();
        czas = max(czas,(long long)Z[v].first) + Z[v].second;
        odp[v] = czas;
      }
      else
        break;
    }
  }
  while(!Q.empty())
  {
    int v = Q.front();
    Q.pop();
    czas = max(czas,(long long)Z[v].first) + Z[v].second;
    odp[v] = czas;
  }
  for(auto ele : odp)
    cout << ele << " ";
  cout << "\n";
  return 0;
}