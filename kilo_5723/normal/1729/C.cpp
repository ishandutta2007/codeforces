#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
using namespace std;
const int alpha = 26, maxn = 2e5 + 5;
char s[maxn];
list<int> lis[alpha];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    for (int i = 0; i < alpha; i++) lis[i].clear();
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 1; i < n - 1; i++) lis[s[i] - 'a'].push_back(i + 1);
    list<int> res;
    if (s[0] < s[n - 1])
      for (int i = s[0]; i <= s[n - 1]; i++)
        res.splice(res.end(), lis[i - 'a']);
    else
      for (int i = s[0]; i >= s[n - 1]; i--)
        res.splice(res.end(), lis[i - 'a']);
    printf("%d %ld\n", abs(s[n - 1] - s[0]), res.size() + 2);
    printf("1 ");
    for (auto v : res) printf("%d ", v);
    printf("%d\n", n);
  }
  return 0;
}