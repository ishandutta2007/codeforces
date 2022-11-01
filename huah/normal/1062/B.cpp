#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    bool flag=false;
    scanf("%d",&n);
    if(n==1){cout<<1<<' '<<0<<endl;return 0;}
    int ans=1,cot=0;
    for(int i=2;i*i<=n;i++)
    {
        int t=0;
        if(n%i==0) ans*=i;
        while(n%i==0) t++,n/=i;
        if(t!=0)
        {
            if(cot==0) cot=t;
            else if(t!=cot)
            {
                flag=true;
                cot=max(cot,t);
            }
        }
    }
    if(n>1)
    {
        if(cot==0) {printf("%d %d\n",n,0);return 0;}
        ans*=n;
        if(cot!=1) flag=true;
    }
    int t=log2(cot);
    if(pow(2,t)==cot)
    {
        if(flag) cot=t+1;
        else cot=t;
    }
    else
        cot=t+1+1;
    printf("%d %d\n",ans,cot);
}