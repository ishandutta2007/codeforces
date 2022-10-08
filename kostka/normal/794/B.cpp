//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define long double double

int main()
{
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int n, h;
  cin >> n >> h;
  double area = h / 2.0;
  double part = area / n;
  vector <double> RES;
  for(int i=1; i<n; i++)
  {
    double a = 0.0, b = h;
    while(b-a > 1e-10)
    {
      double m = (a+b)/2;
      if(m * (m/h) / 2.0 <= (n-i) * part)
        a = m;
      else
        b = m;
    }
    RES.push_back(a);
  }
  reverse(RES.begin(), RES.end());
  for(auto ele : RES)
    cout << ele << " ";
  cout << "\n";
  return 0;
}