//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <int> rep, ile;

int find(int x)
{
  if(rep[x] == x)
    return x;
  return rep[x] = find(rep[x]);
}

void unia(int a, int b)
{
  int fa = find(a);
  int fb = find(b);
  if(fa == fb)
    return;
  if(ile[fa] > ile[fb])
    swap(fa, fb);
  rep[fa] = fb;
  ile[fb] += ile[fa];
  ile[fa] = 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  ile.resize(n);
  rep.resize(n);
  for(int i=0; i<n; i++)
  {
    rep[i] = i;
    ile[i] = 1;
  }
  for(int i=0; i<n; i++)
  {
    int x;
    cin >> x;
    unia(i, x-1);
  }
  int score = 0;
  for(int i=0; i<n; i++)
    if(find(i) == i)
      score++;
  cout << score << "\n";
  return 0;
}