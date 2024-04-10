#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int a, b, c;
   a = b = c = 0;

   int n; cin >> n;
   for(int i = 0; i < n; ++i) {
      char x; cin >> x;
      if(x == 'R')
         a++;
      if(x == 'G')
         b++;
      if(x == 'B')
         c++;
   }
   if(a and b and c)
      cout << "BGR";
   else if(a and b) {
      if(a == 1 and b == 1)
         cout << "B";
      else if(a == 1)
         cout << "BR";
      else if(b == 1)
         cout << "BG";
      else
         cout << "BGR";
   }
   else if(a and c) {
      if(a == 1 and c == 1)
         cout << "G";
      else if(a == 1)
         cout << "GR";
      else if(c == 1)
         cout << "BG";
      else
         cout << "BGR";
   }
   else if(b and c) {
      if(b == 1 and c == 1)
         cout << "R";
      else if(b == 1)
         cout << "GR";
      else if(c == 1)
         cout << "BR";
      else
         cout << "BGR";
   }
   else if(a)
      cout << "R";
   else if(b)
      cout << "G";
   else if(c)
      cout << "B";
}