#include<stdio.h>

long long n,x;

int ans;

int main()
{
    scanf("%I64d%I64d",&n,&x);
    for(long long i=1;i*i<=x;i++){
        if(x%i==0){
            if(i>n || (x/i)>n)continue;
            ans+=2;
            if(i*i==x)ans--;
        }
    }
    printf("%d",ans);
}