#include <bits/stdc++.h>
int main() {
   int n; std::cin >> n;
   if(n <= 3) { std::cout << (n != 3) << '\n'; return 0; }
   int x = 4;
   while(x <= n) {
      if(x == n || x + 1 == n) {
         std::cout << "1\n"; return 0;
      }
      if(x % 2 == 0) x = x * 2 + 1;
      else x = x * 2 + 2;
   }
   std::cout << "0\n";
   return 0;
}