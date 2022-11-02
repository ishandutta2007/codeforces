#include <stdio.h>
#include <string.h>

int main()
{
     char s[201];
     int i;

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
	  if (s[i] == '.') {
	       putchar('0');
	  } else {
	       i++;

	       if (s[i] == '.') {
		    putchar('1');
	       } else {
		    putchar('2');
	       }
	  }
     }
     puts("");

     return 0;
}