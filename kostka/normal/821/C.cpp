//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;


int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <int> ok(n);
  stack <pair <int, int> > Q;
  int toremove = 0, res = 0;
  for(int i=0; i<2*n; i++)
  {
    //cerr << (int)Q.size() << " " << res << "\n";
    string x;
    cin >> x;
    if(x == "add")
    {
      int y;
      cin >> y;
      Q.emplace(y, res+1);
    }
    if(x == "remove")
    {
      toremove++;
      if(Q.empty())
        continue;
      if(Q.top().first != toremove)
      {
        res++;
        while(!Q.empty())
        {
          ok[Q.top().first] = res+1;
          Q.pop();
        }
      }
      else
        Q.pop();
    }
  }
  cout << res << "\n";
}