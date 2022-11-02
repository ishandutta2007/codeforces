#include <stdio.h>

int main()
{
     int n, i;

     scanf("%d", &n);

     if (n == 1) {
	  printf("a\na\nb\nb\n");
     } else if (n == 2) {
	  printf("aa\nbb\naa\nbb\n");
     } else if (n % 2 == 0) {
	  for (i = 0; i < n; i++) {
	       if (i % 4 < 2) {
		    putchar('a');
	       } else {
		    putchar('b');
	       }
	  }
	  puts("");
	  putchar('c');
	  for (i = 0; i < n - 2; i++) {
	       if (i % 4 < 2) {
		    putchar('d');
	       } else {
		    putchar('e');
	       }
	  }
	  puts("c");
	  putchar('c');
	  for (i = 0; i < n - 2; i++) {
	       if (i % 4 < 2) {
		    putchar('e');
	       } else {
		    putchar('d');
	       }
	  }
	  puts("c");
	  for (i = 0; i < n; i++) {
	       if (i % 4 < 2) {
		    putchar('a');
	       } else {
		    putchar('b');
	       }
	  }
	  puts("");
     } else {
	  for (i = 0; i < n - 1; i++) {
	       if (i % 4 < 2) {
		    putchar('a');
	       } else {
		    putchar('b');
	       }
	  }
	  puts("c");
	  for (i = 0; i < n - 1; i++) {
	       if (i % 4 < 2) {
		    putchar('d');
	       } else {
		    putchar('e');
	       }
	  }
	  puts("c");
	  putchar('c');
	  for (i = 0; i < n - 1; i++) {
	       if (i % 4 < 2) {
		    putchar('a');
	       } else {
		    putchar('b');
	       }
	  }
	  puts("");
	  putchar('c');
	  for (i = 0; i < n - 1; i++) {
	       if (i % 4 < 2) {
		    putchar('d');
	       } else {
		    putchar('e');
	       }
	  }
	  puts("");
     }

     return 0;
}