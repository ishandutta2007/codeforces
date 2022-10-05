#include<stdio.h>
int chk[1010],n;
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int t=i,q=1;
        while(t%2==0)t/=2,q*=2;chk[q]=1;q=1;
        while(t%3==0)t/=3,q*=3;chk[q]=1;q=1;
        while(t%5==0)t/=5,q*=5;chk[q]=1;q=1;
        while(t%7==0)t/=7,q*=7;chk[q]=1;q=1;
        while(t%11==0)t/=11,q*=11;chk[q]=1;q=1;
        while(t%13==0)t/=13,q*=13;chk[q]=1;q=1;
        while(t%17==0)t/=17,q*=17;chk[q]=1;q=1;
        while(t%19==0)t/=19,q*=19;chk[q]=1;q=1;
        while(t%23==0)t/=23,q*=23;chk[q]=1;q=1;
        while(t%29==0)t/=29,q*=29;chk[q]=1;q=1;
        while(t%31==0)t/=31,q*=31;chk[q]=1;q=1;
        chk[t]=1;
    }
    int ans=0;
    for(int i=2;i<=n;i++)if(chk[i])ans++;
    printf("%d\n",ans);
    for(int i=2;i<=n;i++)if(chk[i])printf("%d ",i);
}