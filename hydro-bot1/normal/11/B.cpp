// Hydro submission #6263f4649f31360077dcad16@1650717796782
#include<cstdio>
int main() 
{
    int x,ans=0;
    scanf("%d",&x);
    if(x<0) x=-x;
    for(int i=1,t=1;x&&!ans;++i,t+=i)
    {
        if(t==x||(t>x&&!((t-x)%2))) ans=i;
    }
    printf("%d",ans);
    return 0;
}