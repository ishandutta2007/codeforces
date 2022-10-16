#include <stdio.h>
int arr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49},a;
char y[4];
int main()
{
    int i;
    for(i=0;i<19;i++)
    {
        printf("%d\n",arr[i]);
        fflush(stdout);
        scanf("%s",y);
        if(*y=='y')
            a+=i/15+1;
    }
    printf(a>1?"composite":"prime");
}