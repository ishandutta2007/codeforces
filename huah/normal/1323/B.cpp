#include<bits/stdc++.h>
using namespace std;
const int N=40005;
typedef long long ll;
int n,m,k,a[N],b[N],s1[N],t1[N],s2[N],t2[N];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    int t=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) t++;
        else
        {
            if(t) s1[t]++,t1[t]++;
            t=0;
        }
    }
    if(t) s1[t]++,t1[t]++;
    t=0;
    for(int i=1;i<=m;i++)
    {
        if(b[i]==1) t++;
        else
        {
            if(t) s2[t]++,t2[t]++;
            t=0;
        }
    }
    if(t) s2[t]++,t2[t]++;
    for(int i=n;i>=1;i--) s1[i]+=s1[i+1]+t1[i+1],t1[i]+=t1[i+1];
    for(int i=m;i>=1;i--) s2[i]+=s2[i+1]+t2[i+1],t2[i]+=t2[i+1];
    ll ans=0;
    for(int i=1;i<=n;i++)
        if(s1[i]&&k%i==0&&i<=k&&k/i<=m)
    {
        int j=k/i;
        ans+=(ll)s1[i]*s2[j];
    }
    printf("%lld\n",ans);
}