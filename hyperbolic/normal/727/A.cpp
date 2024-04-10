#include <stdio.h>
long long int a,b,ans[110];
int control;
void func(long long int s, int t)
{
    if(s>b) return;
    if(control) return;
    ans[t] = s;
    if(s==b)
    {
        printf("YES\n%d\n",t);
        for(int i=1;i<=t;i++) printf("%I64d ",ans[i]);
        control = 1;
        return;
    }
    func(2*s,t+1);
    func(10*s+1,t+1);
    ans[t] = 0;
}
int main()
{
    scanf("%I64d%I64d",&a,&b);
    func(a,1);
    if(control==0) printf("NO");
}