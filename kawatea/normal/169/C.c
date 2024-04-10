#include <stdio.h>
#include <string.h>

int dp[5000];

int main()
{
     int n1, n2, m = 1000000007, i, j;
     long long sum = 0;
     char s[5001], t[5001];

     scanf("%s", s);
     scanf("%s", t);

     n1 = strlen(s);
     n2 = strlen(t);

     for (i = 0; i < n2; i++) {
	  for (j = n1 - 1; j >= 0; j--) {
	       if (t[i] == s[j]) {
		    dp[j] = (dp[j] + 1) % m;

		    if (j > 0) dp[j] = (dp[j] + dp[j - 1]) % m;
	       }
	  }
     }

     for (i = 0; i < n1; i++) sum = (sum + dp[i]) % m;

     printf("%d\n", (int)sum);

     return 0;
}