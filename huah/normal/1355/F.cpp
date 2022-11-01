#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
bool vis[N];
int tot,ans,p[N];
ll qq[]={998244353,831471112};
ll ss,ct;
ll Q2(ll x)
{
    if(ct+1>22) return 1;
    ct++;
    return __gcd(ss,x);
}
int Q(ll x)
{
    if(ct+1>22) return 1;
    ct++;
    printf("? %lld\n",x);
    fflush(stdout);
    int ans;scanf("%d",&ans);
    return ans;
}
void A(int ans)
{
    printf("! %d\n",ans);
    fflush(stdout);
}
/*
ans/2<=cnt<=ans*2

cnt/2<=cnt<=cnt*2
cnt*2<=cnt<=cnt*8
cnt*3<=cnt<=cnt*12

ans=cnt*4
ans=cnt*6

             most
31627~n     1    1   0   0   0
1009~31607  2    1   2   1   0
179~997     3    0   1   2   3
1e9/1009/1024=967
                 2*2 3*2 2*3 4
40 prim x<=    31  5    30  174
*/
int get(ll x)
{
    int ans=0;
    for(int i=1;i*i<=x;i++)
        if(x%i==0)
    {
        ans++;
        if(x/i!=i) ans++;
    }
    return ans;
}
int main()
{
    for(int i=2;i<=1000;i++)
        if(!vis[i])
    {
        p[++tot]=i;
        for(int j=i+i;j<=1000;j+=i) vis[j]=true;
    }
    //cout<<tot<<' '<<p[tot-6]<<endl;
    int t;scanf("%d",&t);
    while(t--)
    {
        ct=0;
        ll ans=1,sum=1;
        for(int i=1;i<=tot;i++)
        {
            ll res=1;
            while(ans*res*p[i]<=1e9&&res*p[i]<=1024) res*=p[i];
            if(res<=1e18/sum+1&&sum*res<=1e18) sum*=res;
            else
            {
                ans*=Q(sum);sum=res;
            }
        }
        if(sum!=1) ans*Q(sum);
        ans=get(ans);
        A(ans*2);
    }
}