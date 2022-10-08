//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 500007;
long long lef[MAXN], rig[MAXN];

int main()
{
  int n, a, b;
  long long t;
  cin >> n >> a >> b >> t;
  string x;
  cin >> x;
  int wym = 1;
  if(x[0] == 'w')
    wym += b;
  if(t < wym)
  {
    cout << 0 << "\n";
    return 0;
  }
  //cerr << wym << "\n";
  t -= wym;
  //cerr << t << "\n";

  for(int i=1; i<n; i++)
    lef[i] = lef[i-1] + a+1 + ((x[i] == 'w') ? b : 0);
  //for(int i=1; i<n; i++)
  //  cerr << lef[i] << " ";
  //cerr << "\n";
  reverse(x.begin()+1, x.end());
  //cerr << x << "\n";
  for(int i=1; i<n; i++)
    rig[i] = rig[i-1] + 2*a+1 + ((x[i] == 'w') ? b : 0);
  reverse(x.begin()+1, x.end());
  //cerr << x << "\n";

  int res = 0;
  for(int i=0; i<n; i++)
  {
    long long zost = t - lef[i];
    if(zost < 0)
      break;
    auto it = upper_bound(rig+1, rig+n, zost) - rig;
    it--;
    //cerr << i << " " << it << "\n";
    res = max(res, i + (int)it);
  }

  for(int i=1; i<n; i++)
    lef[i] = lef[i-1] + 2*a + 1 + ((x[i] == 'w') ? b : 0);
  reverse(x.begin()+1, x.end());
  for(int i=1; i<n; i++)
    rig[i] = rig[i-1] + a+1 + ((x[i] == 'w') ? b : 0);
  reverse(x.begin()+1, x.end());

  for(int i=0; i<n; i++)
  {
    long long zost = t - lef[i];
    if(zost < 0)
      break;
    auto it = upper_bound(rig+1, rig+n, zost) - rig;
    it--;
    //cerr << i << " " << it << "\n";
    res = max(res, i + (int)it);
  }

  cout << min(res+1, n) << "\n";
  return 0;
}