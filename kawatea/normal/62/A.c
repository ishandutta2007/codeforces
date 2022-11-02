#include <stdio.h>

int main()
{
     int al, ar, bl, br;

     scanf("%d %d %d %d", &al, &ar, &bl, &br);

     if (bl >= ar - 1 && bl <= ar * 2 + 2) {
      puts("YES");
     } else if (br >= al - 1 && br <= al * 2 + 2) {
      puts("YES");
     } else {
      puts("NO");
     }

     return 0;
}