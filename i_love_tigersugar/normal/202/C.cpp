#include <cstdio>
int main()
{
    int x;
    scanf("%d",&x);
    if(x==3)printf("5\n");
    else
    {
    for(int i=1;i<=100;i+=2)
    {
            if(i*i-(i*i)/2>=x)
            {
                printf("%d\n",i);
                break;
            }
    }
}
}