#include "bits/stdc++.h"

using namespace std;

int n;
double res;
double apra;
int l[6], r[6];

void checkprize(int a)
{
  for(int mas=1; mas<(1<<n); mas++)
  {
    bool ok = true;
    double praw = 1.0;
    for(int i=0; i<n; i++)
      if(mas & (1<<i))
        if(!(l[i] <= a and a <= r[i]))
           ok = false;
    for(int i=0; i<n; i++)
      if(mas & (1<<i))
        praw /= (r[i]-l[i]+1);
    if(ok == false)
      continue;
    //cerr << "MAS" << mas << "\n";
    if(__builtin_popcount(mas) != 1)
    {
    double apraw = praw;
    for(int k=0; k<n; k++)
      {
        if((((1<<k) | mas) == mas))
          continue;
        if(l[k] > a)
          apraw *= 0;
        else
          apraw *= 1.0*(min(r[k],a-1)-l[k]+1)/(r[k]-l[k]+1);
      }
      //cerr << a << " " <<  mas << " " << apraw << "\n";
      apra += apraw;
      res += a*apraw;
    }
    for(int j=0; j<n; j++)
    {
      //cerr << "J1" << j << "\n";
      if(((1<<j) | mas) == mas)
        continue;
      //cerr << "J2" << j << "\n";
      if(r[j] <= a)
        continue;
      //cerr << "J3" << j << "\n";
      double tpraw = praw;
      tpraw *= 1.0*(r[j]-max(a+1,l[j])+1)/(r[j]-l[j]+1);
      for(int k=0; k<n; k++)
      {
        if((((1<<k) | mas) == mas) or (k == j))
          continue;
        if(l[k] > a)
          tpraw *= 0;
        else
          tpraw *= 1.0*(min(r[k],a-1)-l[k]+1)/(r[k]-l[k]+1);
      }
      //cerr << a << " " <<  mas << " " << j << " " << tpraw << "\n";
      apra += tpraw;
      res += a*tpraw;
    }
  }
}

int main()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d%d", l+i, r+i);
  for(int i=1; i<=10000; i++)
    checkprize(i);
  //cerr << apra << "\n";
  printf("%.20lf\n", res);
}