#include <stdio.h>
#define MAXL 105

char a[MAXL],b[MAXL];

int main(void)
{
   scanf("%s %s",a,b);
   for(int i=0;a[i];i++)
      printf("%d",a[i]==b[i]?0:1);
   puts("");
}