//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200000;
int war[MAXN+7];
int ccc[MAXN+7];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, k, q;
  cin >> n >> k >> q;
  for(int i=0; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    war[a]++;
    war[b+1]--;
  }
  for(int i=1; i<=MAXN; i++)
    war[i+1] += war[i];
  for(int i=0; i<=MAXN+1; i++)
    if(war[i] >= k)
      ccc[i] = 1;
  for(int i=0; i<=MAXN; i++)
    ccc[i+1] += ccc[i];
  while(q--)
  {
    int a, b;
    cin >> a >> b;
    cout << ccc[b] - ccc[a-1] << "\n";
  }
  return 0;
}