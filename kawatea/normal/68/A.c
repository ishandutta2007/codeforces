#include <stdio.h>

int main()
{
     int p1, p2, p3, p4, a, b;

     scanf("%d %d %d %d %d %d", &p1, &p2, &p3, &p4, &a, &b);

     if (p2 < p1) p1 = p2;
     if (p3 < p1) p1 = p3;
     if (p4 < p1) p1 = p4;

     if (p1 > b) p1 = b + 1;

     if (p1 > a) {
	  printf("%d\n", p1 - a);
     } else {
	  puts("0");
     }

     return 0;
}