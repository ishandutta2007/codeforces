//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  priority_queue <int> M;
  for(int i=0; i<n; i++)
  {
    M.push(4);
    M.push(2);
    M.push(2);
  }
  vector <int> a(k);
  vector <int> A;
  for(int i=0; i<k; i++)
  {
    cin >> a[i];
    while(a[i])
    {
      int e = a[i]%4;
      e = e ? e : 4;
      A.push_back(e);
      a[i] -= e;
    }
  }
  sort(A.begin(), A.end());
  for(int i=0; i<(int)A.size(); i++)
  {
    if(A[i] != 1)
      continue;
    int need = A[i];
    while(need)
    {
      if(M.empty())
      {
        cout << "NO\n";
        return 0;
      }
      int m = M.top();
      M.pop();
      int v = min(need, m);
      need -= v;
      m -= (v+1);
      if(m > 0)
        M.push(m);
    }
  }
  priority_queue <int> N;
  while(!M.empty())
  {
    N.push(-M.top());
    M.pop();
  }
  for(int i=0; i<(int)A.size(); i++)
  {
    if(A[i] == 1)
      continue;
    int need = A[i];
    while(need)
    {
      if(N.empty())
      {
        cout << "NO\n";
        return 0;
      }
      int m = -N.top();
      N.pop();
      int v = min(need, m);
      need -= v;
      m -= (v+1);
      if(m > 0)
        N.push(-m);
    }
  }
  cout << "YES\n";
  return 0;
}