#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,k;
   cin >> n >> k;
   double a = (n+1)*1./k;
   a = ceil(a);
   cout << k*(int)a;
}