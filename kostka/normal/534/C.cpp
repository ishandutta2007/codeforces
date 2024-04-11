//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
long long d[MAXN];

int main()
{
  long long n, k;
  cin >> n >> k;
  long long sum = 0;
  for(int i=0; i<n; i++)
  {
    cin >> d[i];
    sum += d[i];
  }
  for(int i=0; i<n; i++)
  {
    long long l = -sum+k+d[i];
    long long r = k-n+1;
    if(l > r)
      cout << "0 ";
    else
      cout << max(0LL,l-1) + max(0LL,-r+d[i]) << " ";
  }
  cout << "\n";
  return 0;
}