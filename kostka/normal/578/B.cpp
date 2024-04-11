//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, k, x;
  cin >> n >> k >> x;
  vector <long long> V(n);
  for(int i=0; i<n; i++)
    cin >> V[i];
  long long w = 1;
  for(int i=0; i<k; i++)
    w *= x;
  vector <long long> A, B;
  long long a = 0;
  for(int i=0; i<n; i++)
  {
    A.push_back(a);
    a |= V[i];
  }
  long long b = 0;
  for(int i=n-1; i>=0; i--)
  {
    B.push_back(b);
    b |= V[i];
  }
  reverse(B.begin(), B.end());
  long long res = 0;
  for(int i=0; i<n; i++)
    res = max(res, (A[i] | (1LL*V[i]*w) | B[i]));
  cout << res << "\n";
  return 0;
}