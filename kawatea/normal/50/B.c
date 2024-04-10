#include <stdio.h>

int main()
{
     char s[100005];
     int i;
     int a[26] = {0};
     int b[10] = {0};
     long long sum = 0;

     scanf("%s", s);

     for (i = 0; s[i] != '\0'; i++) {
	  if (s[i] >= 'a' && s[i] <= 'z') {
	       a[s[i] - 'a']++;
	  } else {
	       b[s[i] - '0']++;
	  }
     }

     for (i = 0; i < 26; i++) sum += (long long)a[i] * a[i];
     for (i = 0; i < 10; i++) sum += (long long)b[i] * b[i];

     printf("%I64d\n", sum);

     return 0;
}