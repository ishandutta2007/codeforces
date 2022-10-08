//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

map<pair <int, int>, vector <pair <int, int> > > X;

void dodaj(pair <int, int> gdzie, pair <int, int> co)
{
  int a, b, c, i;
  tie(a,b) = gdzie;
  tie(c,i) = co;
  if(a > b)
    swap(a,b);
  auto& inter = X[{a,b}];
  for(auto& ele : inter)
    if(ele.second == i)
    {
      if(ele.first < c)
        ele.first = c;
      return;
    }
  inter.emplace_back(c,i);
  sort(inter.begin(), inter.end());
  reverse(inter.begin(), inter.end());
  while(inter.size() > 2)
    inter.pop_back();
}

int main()
{
  int n;
  cin >> n;
  int best = 0;
  vector <int> RES;
  for(int i=0; i<n; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    if(best < min({a,b,c}))
    {
      best = min({a,b,c});
      RES = {i};
    }
    dodaj({a,b}, {c,i});
    dodaj({a,c}, {b,i});
    dodaj({b,c}, {a,i});
  }

  for(auto ele : X)
  {
    int a, b;
    tie(a,b) = ele.first;
    auto& vec = ele.second;
    if(vec.size() == 2)
    {
      int c1, i1, c2, i2;
      tie(c1, i1) = vec[0];
      tie(c2, i2) = vec[1];
      assert(i1 != i2);
      if(min({a,b,c1+c2}) > best)
      {
        best = min({a,b,c1+c2});
        RES = {i1, i2};
      }
    }
  }


  cout << RES.size() << "\n";
  for(auto res : RES)
    cout << res+1 << " ";
  cout << "\n";

  return 0;
}