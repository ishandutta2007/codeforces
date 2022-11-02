#include <stdio.h>

int main()
{
     int dd, mm, yy, bd, bm, by, f = 0;
     int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

     scanf("%d.%d.%d", &dd, &mm, &yy);
     scanf("%d.%d.%d", &bd, &bm, &by);

     if (yy > by + 18 || (yy == by + 18 && (mm > bm || (mm == bm && dd >= bd)))) {
	  f = 1;
     }

     if (by <= 12 && (d[by - 1] >= bd || (by == 2 && bm % 4 == 0 && bd == 29))) {
	  if (yy > bm + 18 || (yy == bm + 18 && (mm > by || (mm == by && dd >= bd)))) {
	  f = 1;
	  }
     }

     if (bd <= 12 && (d[bd - 1] >= bm || (bd == 2 && by % 4 == 0 && bm == 29))) {
	  if (yy > by + 18 || (yy == by + 18 && (mm > bd || (mm == bd && dd >= bm)))) {
	  f = 1;
	  }
     }

     if (by <= 12 && (d[by - 1] >= bm || (by == 2 && bd % 4 == 0 && bm == 29))) {
	  if (yy > bd + 18 || (yy == bd + 18 && (mm > by || (mm == by && dd >= bm)))) {
	  f = 1;
	  }
     }

     if (d[bm - 1] >= by || (bm == 2 && bd % 4 == 0 && by == 29)) {
	  if (yy > bd + 18 || (yy == bd + 18 && (mm > bm || (mm == bm && dd >= by)))) {
	  f = 1;
	  }
     }

     if (bd <= 12 && (d[bd - 1] >= by || (bd == 2 && bm % 4 == 0 && by == 29))) {
	  if (yy > bm + 18 || (yy == bm + 18 && (mm > bd || (mm == bd && dd >= by)))) {
	  f = 1;
	  }
     }

     if (f == 1) {
	  puts("YES");
     } else {
	  puts("NO");
     }

     return 0;
}