#include <stdio.h>

int main() {
   int t, n;
   int s[100001];
   scanf("%d",&t);
   int i = 0;
   int q = 0;
   int x = 0;
   while(t--) {
      scanf("%d", &s[i]);
      if (i == 0)
          q++;
      if (i > 0 && s[i] == s[i - 1])
      {
          q++;
      }
      if (i > 0 && s[i] != s[i - 1])
      {
          if (x == 0)
              x = q;
          if (q != x)
          {
              printf("NO");
              return 0;
          }
          q = 1;
      }
      i++;
   }
   if (q != x && x != 0)
   {
       printf("NO");
       return 0;
   }
   printf("YES");
}