#include<stdio.h>
#include<math.h>

#define LL long long int
LL max[37],i,j,k,n,a,tmp,cell,t;
LL min(LL x,LL y){
if(x>y){return y;}
else return x;
}

int main()
{
    for(i=1;i<=36;i++)
    {
        max[i]=pow(2,i+1)-1;
    }
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        tmp=0;cell=1;
        scanf("%lld",&a);
        while(a>max[tmp+1]|a<max[tmp])
        {tmp++;}tmp++;
        printf("%lld\n",tmp);
        k=tmp;a-=tmp+1;
        for(j=1;j<=tmp;j++)
        {
            t=min(cell,a/k);
            cell+=t;
            printf("%lld ",t);
            a-=t*k;
            k--;
        }
        printf("\n");
    }
    return 0;
}