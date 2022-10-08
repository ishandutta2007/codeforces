#include "bits/stdc++.h"

using namespace std;

int main()
{
  int s, x1, x2, t1, t2, p, d;
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  if(x1 > x2) 
  {
    x1 = s-x1; 
    x2 = s-x2;
    p = s-p;
    d *= -1;
  }
  cout << min(t2*(x2-x1), t1*(d>0 ? x2-p + (p>x1 ? 2*s : 0) : p+x2)) << "\n";
}