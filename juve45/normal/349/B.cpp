#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, a[88];
string s;

int main()
{
  ios_base::sync_with_stdio(false);
  cin >> n;    
  int mi = 99999999;
  for(int i = 1; i <= 9; i++)
    cin >> a[i], mi = min(mi, a[i]);

  if(n < mi)
  {
    cout << -1;
    return 0;
  }

  while(n >= mi)
  {
    for(int i = 9; i > 0; i--)
      if( (n - mi)/mi == (n - a[i])/mi && n >= a[i])
      {
        cout << i;
        n -= a[i];
        break;
      }
  }

}