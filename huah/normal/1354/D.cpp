#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,q,t[N];
void add(int x,int v)
{
    while(x<=1000000)
        t[x]+=v,x+=x&-x;
}
int del(int x)
{
    int ans=0,sum=0;
    for(int i=1<<19;i;i>>=1)
    {
        if(ans+i<=1000000&&sum+t[ans+i]<x)
            sum+=t[ans+i],ans|=i;
    }
    return ans+1;
}
int main()
{
    scanf("%d%d",&n,&q);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);add(x,1);sum++;
    }
    for(int i=1;i<=q;i++)
    {
        int x;scanf("%d",&x);
        if(x>0) add(x,1),sum++;
        else add(del(-x),-1),sum--;
    }
    printf("%d\n",sum==0?0:del(1));
}