#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
int w[MAXN];
bool m[MAXN];

int main()
{
  int n, k;
  cin >> n >> k;
  long long sum = 0, summia = 0;
  for(int i=0; i<n; i++)
  {
    cin >> w[i];
    sum += w[i];
  }
  for(int i=0; i<k; i++)
  {
    int x;
    cin >> x;
    m[x-1] = true;
    summia += w[x-1];
  }
  long long res = 0;
  for(int i=0; i<n; i++)
  {
    if(m[i])
      res += 1LL*w[i]*(sum-w[i]);
    else
    {
      res += 1LL*w[i]*summia;
      if(m[(i-1+n)%n] == false)
        res += 1LL*w[i]*w[(i-1+n)%n];
      if(m[(i+1)%n] == false)
        res += 1LL*w[i]*w[(i+1)%n];
    }
  }
  cout << res / 2 << "\n";
}