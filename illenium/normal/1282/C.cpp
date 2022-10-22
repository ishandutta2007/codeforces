#include<bits/stdc++.h>
#include <cstdio>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
#include<string>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
const int mod=998244353;
struct pp
{
    int f;
    int tt;
    bool operator <(pp &k)
    {
        return tt<k.tt;
    }
}aa[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,T,a,b;
        ll diff=0,easy=0;
        scanf("%d%d%d%d",&n,&T,&a,&b);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&aa[i].f);
            if(aa[i].f==1)diff++;
            else easy++;
        }
        for(int i=1;i<=n;i++)
            scanf("%d",&aa[i].tt);
        sort(aa+1,aa+n+1);
        aa[n+1].tt=T+1;
        ll sum=0,ans=0,ans1=0,ff=0;
        for(int i=0;i<=n;i++)
        {
            if(i!=0)
            {
                if(aa[i].f)sum+=b,diff--;
                else sum+=a,easy--;
            }
            if((i==0||i==n||aa[i].tt!=aa[i+1].tt)&&sum<=T&&sum<aa[i+1].tt)
            {
                ll res=aa[i+1].tt-sum-1;
                ll mi=min(easy,res/a);
                res-=mi*a;
                ll ma=min(diff,res/b);
                ans=max(ans,i+mi+ma);;
            }
            if(sum>T)break;
        }
        printf("%lld\n",ans);
    }
}