#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[65],ans,x,n,m;
int main()
{
    //ios::sync_with_stdio(0);
    int t;

    cin>>t;
    while(t--)
    {

for(int i=0;i<64;i++){d[i]=0;}
scanf("%lld%lld",&n,&m);

for(int i=0;i<m;i++)
{scanf("%lld",&x);x=log2(x);d[x]++;}
//if(m>n){cout<<-1<<endl;continue;}
ll ans=0;
for(int i=0;i<63;i++)
{
   // cout<<d[i]<<endl;
    if(n&(1LL<<i))d[i]--;
    if(d[i]==0)continue;
    if(d[i]<0){ans+=(-1*d[i]+1)/2;d[i+1]-=(-1*d[i]+1)/2;continue;}


d[i+1]+=d[i]/2;
}
if(d[63]<0){printf("-1\n");continue;}
  printf("%lld\n",ans);
    }
    return 0;
}