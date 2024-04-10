#include <stdio.h>

int main()
{
     int n;

     scanf("%d", &n);

     if (n <= 10 || n >= 22) {
	  puts("0");
     } else if (n < 20) {
	  puts("4");
     } else if (n == 20) {
	  puts("15");
     } else {
	  puts("4");
     }

     return 0;
}