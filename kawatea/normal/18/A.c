#include <stdio.h>

int diff(int x1, int y1, int x2, int y2)
{
     return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int right(int x[3], int y[3])
{
     int d1 = diff(x[0], y[0], x[1], y[1]);
     int d2 = diff(x[0], y[0], x[2], y[2]);
     int d3 = diff(x[1], y[1], x[2], y[2]);

     if (d1 == 0 || d2 == 0 || d3 == 0) return 0;

     if (d1 < d2) {
	  int tmp = d1; d1 = d2; d2 = tmp;
     }

     if (d1 < d3) {
	  int tmp = d1; d1 = d3; d3 = tmp;
     }

     if (d1 == d2 + d3) {
	  return 1;
     } else {
	  return 0;
     }
}

int main()
{
     int i, j, k;
     int x[3], y[3];
     int d[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

     for (i = 0; i < 3; i++) scanf("%d %d", &x[i], &y[i]);

     if (right(x, y) == 1) {
	  puts("RIGHT");
     } else {
	  for (i = 0; i < 3; i++) {
	       for (j = 0; j < 4; j++) {
		    int s[3], t[3];

		    for (k = 0; k < 3; k++) {
			 s[k] = x[k];
			 t[k] = y[k];
		    }

		    s[i] += d[j][0];
		    t[i] += d[j][1];

		    if (right(s, t) == 1) {
			 puts("ALMOST");

			 return 0;
		    }
	       }
	  }

	  puts("NEITHER");
     }

     return 0;
}