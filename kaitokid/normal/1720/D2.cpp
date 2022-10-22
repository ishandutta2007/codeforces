#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[20000009][2][2];
int ch[20000009][2];
int id;
int nw()
{
    id++;
    dp[id][0][0]=dp[id][0][1]=dp[id][1][0]=dp[id][1][1]=0;
    ch[id][0]=ch[id][1]=-1;
    return id;

}

int go(int x,int u)
{
    int r=0,res=0;
    for(int i=30;i>=0;i--)
    {
        res=max(res,dp[r][(((1<<i)&x)==0)][(((1<<i)&u)!=0)]);
     //   cout<<u<<" "<<x<<" "<<r<<" "<<(((1<<i)&x)==0)<<" "<<(((1<<i)&u)!=0)<<endl;
        if(ch[r][(((x^u)&(1<<i))!=0)]==-1)return res;
        r=ch[r][(((x^u)&(1<<i))!=0)];
    }
    return res;
}
void upd(int x,int u,int res)
{
    int r=0;
    for(int i=30;i>=0;i--)
    {
        dp[r][(((1<<i)&u)!=0)][(((1<<i)&x)!=0)]=max(res,dp[r][(((1<<i)&u)!=0)][(((1<<i)&x)!=0)]);
        if(ch[r][(((x^u)&(1<<i))!=0)]==-1)ch[r][(((x^u)&(1<<i))!=0)]=nw();
        r=ch[r][(((x^u)&(1<<i))!=0)];
    }

}
int main()
{

int t;
scanf("%d",&t);
while(t--)
{
    id=-1;
    nw();

    int n;
    scanf("%d",&n);
    int ans=0;
    for(int u=0;u<n;u++){int x,res=1;
    scanf("%d",&x);
    res=max(res,1+go(x,u));
  //  cout<<u<<" "<<x<<" "<<res<<endl;
    ans=max(ans,res);
    upd(x,u,res);
    }
    printf("%d\n",ans);
}
return 0;
}