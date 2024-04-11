//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
int d[MAXN], e[MAXN];

int go(int a, int b)
{
  return abs(d[a]-d[b]);
}

int main()
{
  int n;
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> d[i];
  int m;
  cin >> m;
  for(int i=0; i<m; i++)
  {
    int a;
    cin >> a;
    e[a]++;
  }
  long long dl = 0;
  int a = 1, kier = 1;
  e[1]--;
  for(int i=1; i<m; i++)
  {
    dl += go(a, a+kier);
    a = a+kier;
    e[a]--;
    if(a==n or a==1)
      kier *= -1;
  }
  set <int> NZ;
  set <long long> D;
  for(int i=1; i<=n; i++)
    if(e[i])
      NZ.insert(i);
  if(NZ.empty())
    D.insert(dl);
  for(int i=2; i<=n; i++)
  {
    dl -= go(i-1, i);
    if(e[i-1]==-1)
      NZ.erase(i-1);
    if(e[i-1]==0)
      NZ.insert(i-1);
    e[i-1]++;
    dl += go(a, a+kier);
    a = a+kier;
    if(e[a]==1)
      NZ.erase(a);
    if(e[a]==0)
      NZ.insert(a);
    e[a]--;
    if(a==n or a==1)
      kier *= -1;
    if(NZ.empty())
      D.insert(dl);
  }
  for(int i=n-1; i>=1; i--)
  {
    dl -= go(i+1, i);
    if(e[i+1]==-1)
      NZ.erase(i+1);
    if(e[i+1]==0)
      NZ.insert(i+1);
    e[i+1]++;
    dl += go(a, a+kier);
    a = a+kier;
    if(e[a]==1)
      NZ.erase(a);
    if(e[a]==0)
      NZ.insert(a);
    e[a]--;
    if(a==n or a==1)
      kier *= -1;
    if(NZ.empty())
      D.insert(dl);
  }
  if((int)D.size() != 1)
    cout << "-1\n";
  else
    cout << *(D.begin()) << "\n";
  return 0;
}