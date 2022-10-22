#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long llint;
typedef pair<int, int> point;

int a[150];
int ones;
vector<llint> v;

int main() {
   llint sol = 1LL, tmp = 1LL;
   llint n; cin >> n;
   for(llint i = 0; i < n; ++i) {
      cin >> a[i];
      if(a[i])
         ones++;
   }
   if(!ones)
   {
      cout << 0;
      return 0;
   }
   for(llint i = 0; i < n; ++i) {
      if(a[i]) {
         v.push_back(tmp);
         tmp = 1LL;
      }
      if(!a[i])
         tmp += 1LL;
   }
   for(llint i = 1; i < v.size(); ++i)
      sol *= v[i];
   cout << sol;
   return 0;
}