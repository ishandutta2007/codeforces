#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main() {
   int test; scanf("%d", &test);
   while(test --) {
      scanf("%d", &n);
      vector<int> vec;
      int x = 1;
      while(n) {
         vec.push_back(min(x, n));
         n -= min(n, x); x <<= 1;
      }
      sort(vec.begin(), vec.end());
      printf("%d\n", (int) vec.size() - 1);
      for(int i = 1; i < (int) vec.size(); i++) {
         printf("%d ", vec[i] - vec[i - 1]);
      }
   }
   return 0;
}