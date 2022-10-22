#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[200000],diff[200000];
int main(){
    ll n,i,j,sq=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",num+i);
        ll cur=0;
        for(j=1<<15;j;j>>=1)if((cur+j)*(cur+j)<=num[i])cur+=j;
        diff[i]=min(num[i]-cur*cur,(cur+1)*(cur+1)-num[i]);
        if(diff[i]==0)sq++;
    }
    if(sq>n/2){
        ll notzero=0;
        for(i=0;i<n;i++)if(num[i]!=0&&diff[i]==0)notzero++;
        if(notzero>=sq-n/2)printf("%d",sq-n/2);
        else printf("%lld",notzero+(sq-n/2-notzero)*2);
    }
    else{
        sort(diff,diff+n);
        ll ans=0;
        for(i=0;i<n/2;i++)ans+=diff[i];
        printf("%lld",ans);
    }
}