//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

map <pair <int, long long>, int> ILE;

int winning(int stos, long long moves)
{
  if(ILE.find(make_pair(stos, moves)) != ILE.end())
    return ILE[make_pair(stos, moves)];
  set <int> X;
  for(int i=1; i<=stos; i++)
    if(moves & (1<<i))
      X.insert(winning(stos-i, moves^(1<<i)));
  int ile = 0;
  while(true)
  {
    if(X.find(ile) == X.end())
      return ILE[make_pair(stos, moves)] = ile;
    ile++;
  }
}

int main()
{
  vector <int> W = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
  /*/
  for(int i=1; i<=60; i++)
  {
    ILE.clear();
    cerr << winning(i, (1LL<<62)-1) << ", ";
  }
  cerr << (int)W.size() << "\n";
  /*/
  int n;
  cin >> n;
  vector <int> s(n);
  for(int i=0; i<n; i++)
    cin >> s[i];
  int sg = 0;
  for(int i=0; i<n; i++)
    sg ^= W[s[i]];
  cout << (sg ? "NO" : "YES") << "\n";
  return 0;
}