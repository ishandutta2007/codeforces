//A
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500005],t[500005],same[500005],cur,ans,tmp;

int main()
{
    ll i,j;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++) {
        scanf("%I64d",&a[i]);
        t[i]=t[i-1]*(a[i]==a[i-1])+1;
    }
    for(i=n;i>0;i--) {
        if(t[i]==t[i+1]-1) {
            same[i]=same[i+1];
        }
        else same[i]=t[i];
    }
    for(i=2;i<n;i++) {
        if(same[i]==1) {
            cur++;
        }
        else if(cur!=0) {
            if(cur%2) {
                ans=max(cur/2+1,ans);
                tmp=a[i-cur+1];
                for(j=i-cur;j<i;j++) {
                    a[j]=tmp;
                }
            }
            else {
                ans=max(cur/2,ans);
                tmp=a[i-cur+1];
                for(j=i-cur;j<i-cur/2;j++) {
                    a[j]=tmp;
                }
                tmp=1-tmp;
                for(j=i-cur/2;j<i;j++) {
                    a[j]=tmp;
                }
            }
            cur=0;
        }
    }
    if(cur!=0) {
        if(cur%2) {
            ans=max(cur/2+1,ans);
            tmp=a[i-cur+1];
            for(j=i-cur;j<i;j++) {
                a[j]=tmp;
            }
        }
        else {
            ans=max(cur/2,ans);
            tmp=a[i-cur+1];
            for(j=i-cur;j<i-cur/2;j++) {
                a[j]=tmp;
            }
            tmp=1-tmp;
            for(j=i-cur/2;j<i;j++) {
                a[j]=tmp;
            }
        }
        cur=0;
    }
    printf("%I64d\n",ans);
    for(i=1;i<=n;i++) {
        printf("%I64d ",a[i]);
    }
}