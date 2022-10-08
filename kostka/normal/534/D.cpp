//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <int> V[200007], ANS;

bool check(int n)
{
  int a = 0;
  for(int i=0; i<n; i++)
  {
    while(V[a].empty())
    {
      a -= 3;
      if(a < 0)
        return false;
    }
    ANS.push_back(V[a].back());
    V[a].pop_back();
    a++;
  }
  return true;
}

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int a;
    cin >> a;
    V[a].push_back(i);
  }
  if(check(n))
  {
    puts("Possible");
    for(auto ele : ANS)
      cout << ele+1 << " ";
    cout << "\n";
  }
  else
   puts("Impossible");
  return 0;
}