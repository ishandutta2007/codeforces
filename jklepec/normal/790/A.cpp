#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

int cookie = 0;

string name(int x) {
   string ret = "";
   ret += 'A' + (x / 26);
   ret += 'a' + (x % 26);
   return ret;
}

string sol[100];

int main() {
   int n, k; cin >> n >> k;

   string first;
   cin >> first;
   if(first == "NO") {
      sol[0] = name(0);
      REP(i, k - 1) {
         sol[i + 1] = name(cookie++);
      }
   }
   else {
      REP(i, k) {
         sol[i] = name(cookie++);
      }
   }

   REP(i, n - k) {
      cin >> first;
      if(first == "NO") {
         sol[i + k] = sol[i + 1];
      }
      else {
         sol[i + k] = name(cookie++);
      }
   }

   REP(i, n) cout << sol[i] << " ";
}