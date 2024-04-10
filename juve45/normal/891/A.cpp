#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 2010

using namespace std;

int n, k, x, a[DMAX], g[DMAX];
string s;

int main()
{
	int x = 0;
	ios_base::sync_with_stdio(false);
  cin >> n;

  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
    if(a[i] == 1)
    	x++;
  }
  if(x == n)
  {
  	cout << "0\n";
  	return 0;
  }

  if(x > 0)
  {
  	cout << n - x;
  	return 0;
  }
  
  for(int i = 1; i <= n ; i++)
  {
    for(int j = 1; j + i - 1 <= n; j++)
    {
      g[j] = __gcd(g[j], a[j + i - 1]);
      if(g[j] == 1)
      {
        cout << i + n - 2; 
        return 0;
      }
    }
    //dbg_v(g, n + 1);
  }
  cout << "-1\n";
  return 0;
}