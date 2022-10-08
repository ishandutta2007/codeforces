#include "bits/stdc++.h"

using namespace std;

int main()
{
  vector <int> A, B;
  int n;
  cin >> n;
  long long suma1 = 0, suma2 = 0;
  string last = "";
  for(int i=0; i<n; i++)
  {
    int a;
    cin >> a;
    if(a>0)
    {
      suma1 += a;
      A.push_back(a);
      last = "first";
    }
    else
    {
      suma2 -= a;
      B.push_back(-a);
      last = "second";
    }
  }
  if(suma1 > suma2)
  {
    puts("first");
    return 0;
  }

  if(suma1 < suma2)
  {
    puts("second");
    return 0;
  }
  if(A==B)
  {
    cout << last;
    return 0;
  }
  puts(A > B ? "first" : "second");
}