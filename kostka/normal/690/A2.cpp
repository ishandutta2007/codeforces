#include "bits/stdc++.h"

using namespace std;

//          1 - 0       //         10 - 0
//         11 - 1       //        100 - 0
//        101 - 2       //        110 - 1
//        111 - 3       //       1000 - 0
//       1001 - 4       //       1010 - 1
//       1011 - 5       //       1100 - 2

int main()
{
  int n;
  cin >> n;
  if(n%2)
    cout << (n-1)/2 << "\n";
  else
  {
    n -= 1<<(31-__builtin_clz(n));
    n /= 2;
    cout << n << "\n";
  }
}