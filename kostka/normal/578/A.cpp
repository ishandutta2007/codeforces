//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

double eps = 1e-9;

int main()
{
  vector <double> res;
  int a, b;
  scanf("%d%d", &a, &b);
  if(a==b)
  {
    printf("%.20lf\n", (double)b);
    return 0;
  }
  double w = a - b;
  int k = 1, l = 1000000003;
  while(k+1 < l)
  {
    int m = (k+l)/2;
    if(w / (2*m) >= b)
      k = m;
    else
      l = m;
  }
  if(k > 0 and w / (2*k) >= b)
    res.push_back(w/(2*k));
  w = a+b;
  k = 1; l = 1000000003;
  while(k+1 < l)
  {
    int m = (k+l)/2;
    if(w / (2*m) >= b)
      k = m;
    else
      l = m;
  }
  if(k > 0 and w / (2*k) >= b)
    res.push_back(w/(2*k));
  sort(res.begin(), res.end());
  if(res.empty())
    puts("-1");
  else
    printf("%.20lf\n", (*res.begin()));
  return 0;
}