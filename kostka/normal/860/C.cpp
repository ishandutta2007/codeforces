//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

set <string> used;

string random_string()
{
  string x;
  do {
    x = "";
    for(int i=0; i<6; i++)
      x += 'a'+rand()%26;
  } while(used.find(x) != used.end());
  used.insert(x);
  return x;
}

int main()
{
  ios_base::sync_with_stdio(0);
  srand(15061994);
  int n;
  cin >> n;
  vector <string> test(n+1);
  vector <int> example(n+1);
  vector <int> pos(n+1), test_pos(n+1);
  vector <int> E[2];
  set <int> P[2], B[2];
  vector <pair <string, string> > res;
  for(int i=1; i<=n; i++)
  {
    cin >> test[i] >> example[i];
    E[example[i]].push_back(i);
    used.insert(test[i]);
    try
    {
      int e = stoi(test[i]);
      if(0 <= e and e <= n and to_string(e) == test[i])
      {
        pos[e] = i;
        test_pos[i] = e;
      }
    }
    catch(const exception& e)
    {
      continue;
    }
  }
  int e = (int)E[1].size();
  for(int i=1; i<=n; i++)
  {
    if(test_pos[i])
      if(example[i] != (test_pos[i] <= e))
        B[test_pos[i] <= e ? 1 : 0].insert(i);
  }
  for(int i=1; i<=n; i++)
    if(!pos[i])
      P[i <= e ? 1 : 0].insert(i);
  for(int i=0; i<2; i++)
  {
    for(auto& b : B[i])
      cerr << b << " ";
    cerr << "\n";
  }
  while(!B[0].empty() or !B[1].empty())
  {
    bool cont = false;
    for(int i=0; i<2; i++)
    {
      if(!B[i].empty() and !P[1-i].empty())
      {
        int v = *(B[i].begin());
        int w = *(P[1-i].begin());
        res.emplace_back(test[v], to_string(w));
        B[i].erase(v);
        P[1-i].erase(w);
        P[i].insert(test_pos[v]);
        test_pos[v] = w;
        cont = true;
      }
    }
    if(cont)
      continue;
    for(int i=0; i<2; i++)
    {
      if(!B[i].empty() and P[1-i].empty())
      {
        int v = *(B[i].begin());
        string x = random_string();
        res.emplace_back(test[v], x);
        P[i].insert(test_pos[v]);
        test_pos[v] = 0;
        B[i].erase(v);
        test[v] = x;
      }
    }
  }
  for(int i=1; i<=n; i++)
  {
    if(test_pos[i] == 0)
    {
      int v = (*P[example[i]].begin());
      res.emplace_back(test[i], to_string(v));
      P[example[i]].erase(v);
    }
  }
  cout << (int)res.size() << "\n";
  for(auto& r : res)
    cout << "move " << r.first << " " << r.second << "\n";
  return 0;
}