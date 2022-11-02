#include<cstdio>
int i,n,c,t,m;

int main()
{
    scanf("%d",&n);
    for(i=n;i;i/=10) {
        if(i%10>m)m=i%10;
    }
    printf("%d\n",m);
    for(;n;){
        for(i=1;i<=n;i*=10) {
            if(n/i%10){
                t+=i;
            }
        }
        printf("%d ",t);
        n-=t;
        t=0;
    }
}