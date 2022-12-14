#include <stdio.h>
char x[200010];
int main()
{
    int a,b,c,d=0;
    scanf("%d%d",&a,&b);
    scanf("%s",x+1);
    for(int i=1;i<=a;i++) if(x[i]=='.') c = i;
    for(int i=c+1;x[i]!=0;i++)
    {
        if(x[i]>='5')
        {
            d = i;
            break;
        }
    }
    if(d==0)
    {
        printf("%s",x+1);
        return 0;
    }
    for(int i=1;i<=b;i++)
    {
        if(d>=c+2)
        {
            x[d-1]++;
            d--;
        }
        else if(d==c+1)
        {
            x[d-2]++;
            d-=2;
        }
        while(x[d]>'9')
        {
            if(d==c+1) x[d]='0',x[d-2]++,d-=2;
            else if(d>=1)x[d]='0',x[d-1]++,d--;
            else break;
        }
        if(d>=c+1) x[d+1] = 0;
        else x[c] = 0;
        if(d<c) break;
        else if(x[d]<='4') break;
    }
    if(x[0]==1) printf("1%s",x+1);
    else printf("%s",x+1);
}