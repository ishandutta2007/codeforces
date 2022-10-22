#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=5e5+10;
bool pr[mn],in[mn];
int u[mn],num[mn];
int cur[mn];
int main()
{
    int n,q,i,j;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)scanf("%d",num+i);
    memset(pr,1,sizeof(pr));
    for(i=1;i<mn;i++)u[i]=1;
    for(i=2;i*i<mn;i++)if(pr[i])for(j=i*i;j<mn;j+=i)pr[j]=0;
    for(i=2;i<mn;i++){
        if(pr[i]){
            for(j=i;j<mn;j+=i){
                u[j]=-u[j];
                if(j%(1LL*i*i)==0)u[j]=0;
            }
        }
    }
    int x;
    ll ans=0;
    while(q--){
        scanf("%d",&x);
        int t=num[x];
        if(!in[x]){
            for(i=1;i*i<t;i++){
                if(t%i==0){
                    ans+=u[i]*cur[i]+u[t/i]*cur[t/i];
                    cur[i]++;
                    cur[t/i]++;
                }
            }
            if(t==i*i){
                ans+=u[i]*cur[i];
                cur[i]++;
            }
        }
        else{
            for(i=1;i*i<t;i++){
                if(t%i==0){
                    cur[i]--,cur[t/i]--;
                    ans-=u[i]*cur[i]+u[t/i]*cur[t/i];
                }
            }
            if(t==i*i){
                cur[i]--;
                ans-=u[i]*cur[i];
            }
        }
        in[x]^=1;
        printf("%lld\n",ans);
    }
}