//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

bool check01(vector <int> &A)
{
  for(auto ele : A)
    if(abs(ele) > 1)
      return false;
  return true;
}

long long w, m;

int main()
{
  cin >> w >> m;
  long long i = 1;
  vector <int> V;
  while(i <= m)
  {
    V.push_back((m/i) % w);
    i *= w;
  }
  if(check01(V))
  {
    puts("YES");
    return 0;
  }
  for(int i=0; i<min((int)V.size(), 100); i++)
  {
    //cout << V[i] << " ";
    if(V[i] != 0 and V[i] != 1)
    {
      if(i+1 == (int)V.size())
        V.push_back(0);
      V[i+1] += 1;
      V[i] -= w;
      //cout << ": " << V[i] << " ";
      if(V[i] != 0 and V[i] != -1)
      {
        puts("NO");
        return 0;
      }
    }
  }
  if(check01(V))
    puts("YES");
  else
    puts("NO");
  return 0;
}