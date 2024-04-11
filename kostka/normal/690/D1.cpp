#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  string buf;
  for(int i=0; i<n; i++)
    cin >> buf;
  vector <int> X;
  for(int i=0; i<m; i++)
    if(buf[i] == 'B')
      X.push_back(i);
  int res = 0;
  for(int i=0; i<(int)X.size(); i++)
  {
    while(i+1 < (int)X.size() and X[i+1] - X[i] == 1)
      i++;
    res++;
  }
  cout << res << "\n";
}