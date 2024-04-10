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

   int n; cin >> n;

   string s;
   cin >> s;

   int sol = 0;
   for(int i = 0; i < n; ++i) {
      int x = 0, y = 0;
      for(int j = i; j < n; ++j) {
         if(s[j] == 'U')
            x += 1;
         if(s[j] == 'L')
            y -= 1;
         if(s[j] == 'D')
            x -= 1;
         if(s[j] == 'R')
            y += 1;
         if(x == 0 and y == 0)
            sol ++;
      }
   }
   cout << sol;
}