#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[3],d[8],td[8],x[200005],t,tmm,ans,t1,t2,ma=1e18,ta;

int main()
{
    int i,j;
    scanf("%lld%lld%lld%lld",&n,&a[0],&a[1],&a[2]);
    sort(a,a+3);
    if(a[0]+a[1]>a[2]) {
        for(i=0;i<n;i++) {
            scanf("%lld",&t);
            if(t>a[0]+a[1]+a[2]) {puts("-1");return 0;}
            else if(t>a[1]+a[2]) d[0]++;
            else if(t>a[0]+a[2]) d[1]++;
            else if(t>a[0]+a[1]) d[2]++;
            else if(t>a[2]) d[3]++;
            else if(t>a[1]) d[4]++;
            else if(t>a[0]) d[5]++;
            else d[6]++;
        }
        ans+=d[0];
        ans+=d[1]; tmm=d[1];
        for(i=6;i<=6;i++){t=tmm; tmm-=min(t,d[i]); d[i]-=min(t,d[i]);}
        ans+=d[2]; tmm=d[2];
        for(i=5;i<=6;i++){t=tmm; tmm-=min(t,d[i]); d[i]-=min(t,d[i]);}
        ans+=d[3]; tmm=d[3];
        for(i=4;i<=6;i++){t=tmm; tmm-=min(t,d[i]); d[i]-=min(t,d[i]);}
        t1=d[4]; t2=(d[5]>=d[6]?d[5]:d[5]+(d[6]-d[5]+1)/2);
        if(t1>t2) ans+=t2+(t1-t2+1)/2;
        else {
            ans+=t1; tmm=t1;
            for(i=5;i<=6;i++){t=tmm; tmm-=min(t,d[i]); d[i]-=min(t,d[i]);}
            tmm=t1;
            for(i=6;i<=6;i++){t=tmm; tmm-=min(t,d[i]); d[i]-=min(t,d[i]);}
            ans+=(d[5]+1)/2;
            if(d[6]>0 && d[5]%2) d[6]--;
            d[6]=max(0ll,d[6]-(d[5]+1)/2);
            ans+=(d[6]+2)/3;
        }
    }
    else {
        for(i=0;i<n;i++) {
            scanf("%lld",&t);
            if(t>a[0]+a[1]+a[2]) {puts("-1");return 0;}
            else if(t>a[1]+a[2]) d[0]++;
            else if(t>a[0]+a[2]) d[1]++;
            else if(t>a[2]) d[2]++;
            else if(t>a[0]+a[1]) d[3]++;
            else if(t>a[1]) d[4]++;
            else if(t>a[0]) d[5]++;
            else d[6]++;
        }
        ans+=d[0];
        ans+=d[1]; tmm=d[1];
        for(i=6;i<=6;i++){t=tmm; tmm-=min(t,d[i]); d[i]-=min(t,d[i]);}
        ans+=d[2]; tmm=d[2];
        for(i=5;i<=6;i++){t=tmm; tmm-=min(t,d[i]); d[i]-=min(t,d[i]);}
        for(j=0;j<=d[3];j++) {
            td[4]=d[4]; td[5]=d[5]; td[6]=d[6]; ta=d[3];
            tmm=j;
            for(i=5;i<=6;i++){t=tmm; tmm-=min(t,td[i]); td[i]-=min(t,td[i]);}
            tmm=j;
            for(i=6;i<=6;i++){t=tmm; tmm-=min(t,td[i]); td[i]-=min(t,td[i]);}
            td[4]=max(0ll,td[4]-d[3]+j);
            t1=td[4]; t2=(td[5]>=td[6]?td[5]:td[5]+(td[6]-td[5]+1)/2);
            if(t1>t2) ta+=t2+(t1-t2+1)/2;
            else {
                ta+=t1; tmm=t1;
                for(i=5;i<=6;i++){t=tmm; tmm-=min(t,td[i]); td[i]-=min(t,td[i]);}
                tmm=t1;
                for(i=6;i<=6;i++){t=tmm; tmm-=min(t,td[i]); td[i]-=min(t,td[i]);}
                ta+=(td[5]+1)/2;
                if(td[6]>0 && td[5]%2) td[6]--;
                td[6]=max(0ll,td[6]-(td[5]+1)/2);
                ta+=(td[6]+2)/3;
            }
            ma=min(ma,ta);
        }
        ans+=ma;
    }
    printf("%lld",ans);
}