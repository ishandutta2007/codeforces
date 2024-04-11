#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n;
  cin >> n;
  unordered_map <char, int> M;
  string y;
  cin >> y;
  int ans = n;
  for(auto lit : y)
    M[lit] = -1;
  for(int i=0; i<n; i++)
  {
    M[y[i]] = i;
    bool ok = true;
    int res = i;
    for(auto ele : M)
    {
      if(ele.second == -1)
        ok = false;
      else
        res = min(res, ele.second);
    }
    if(ok)
      ans = min(i-res+1, ans);
  }
  cout << ans << "\n";
}