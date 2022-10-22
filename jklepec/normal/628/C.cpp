#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for(int i = a; i < b; ++i)

const int MAXN = 1e5 + 5;

char s[MAXN];
string sol = "";

int main() {

   int n, k;

   scanf("%d%d%s", &n, &k, s);

   for(int i = 0; i < n; ++i) {

      int x = s[i] - 'a' + 1;

      if(x > 13) {
         x = min(x - 1, k);
         k -= x;

         sol += char(s[i] - x);
      }
      else {
         x = min(26 - x, k);
         k -= x;

         sol += char(s[i] + x);
      }

   }

   if(k)
      printf("%d", -1);
   else
      for(int i = 0; i < n; ++i)
         printf("%c", sol[i]);
}