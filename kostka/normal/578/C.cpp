//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

double eps = 1e-11;

double check(double avg, int n, vector <double> &V)
{
  double res = 0.0, pref = 0.0;
  double minx = 0.0, maxx = 0.0;
  for(int i=0; i<n; i++)
  {
    pref += V[i]-avg;
    res = max(res, abs(pref-minx));
    res = max(res, abs(pref-maxx));
    minx = min(minx, pref);
    maxx = max(maxx, pref);
  }
  return res;
}

int main()
{
  int n;
  scanf("%d", &n);
  vector <double> V(n);
  for(int i=0; i<n; i++)
    scanf("%lf", &V[i]);
  double k = -10007.0, l  = 10007.0;
  while(abs(l-k) > eps)
  {
    double p = k + (l - k)/3;
    double q = l - (l - k)/3;
    if(check(p,n,V) > check(q,n,V))
      k = p;
    else
      l = q;
  }
  printf("%.20lf\n", check((k+l)/2,n,V));
  return 0;
}