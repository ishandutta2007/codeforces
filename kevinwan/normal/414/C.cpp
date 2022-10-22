#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1<<20;
int k[mn],ex[mn];
ll num[mn],mos[mn];
void solve(int n,int a){
    if(n==0)return;
    solve(n-1,a);
    solve(n-1,a+(1<<n-1));
    int l=a,r=a+(1<<n-1),i=0;
    while(l<a+(1<<n-1)&&r<a+(1<<n)){
        if(k[l]<=k[r]){
            ex[i++]=k[l++];
        }
        else{
            ex[i++]=k[r++];
            num[n]+=a+(1<<n-1)-l;
        }
    }
    while(l<a+(1<<n-1))ex[i++]=k[l++];
    while(r<a+(1<<n))ex[i++]=k[r++];
    for(i=0;i<1<<n;i++)k[i+a]=ex[i];
    mos[n]+=1LL*(1<<n)*((1<<n)-1)/2;
    int num=1;
    ll ans=0;
    for(i=1;i<1<<n;i++){
        if(ex[i]==ex[i-1])num++;
        else num=1;
        ans+=num-1;
    }
    mos[n]-=ans;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<1<<n;i++){
        scanf("%d",k+i);
    }
    solve(n,0);
    for(i=1;i<=n;i++)num[i]+=num[i-1];
    int q;
    scanf("%d",&q);
    while(q--){
        int a;
        scanf("%d",&a);
        for(i=0;i<a;i++)num[i]=mos[i]-num[i];
        ll dif=mos[i]-num[i]*2;
        for(i=a;i<=n;i++)num[i]+=dif;
        printf("%lld\n",num[n]);
    }
}