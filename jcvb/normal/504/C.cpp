#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
typedef long long ll;
int a[100005];
int tms[100005]={0};

int len=-1;

int tim[100005]={0};
int checkl(int r){
    int bo=0;
    for (int i=1;i<=n;i++)tim[i]=0;
    if(r<=n/2){
        for (int i=r+1;i<=n/2;i++)if(a[i]!=a[n+1-i])return 0;
        for (int i=n-r+1;i<=n-len;i++)tim[a[i]]++;
        for (int i=len+1;i<=r;i++)tim[a[i]]--;
        for (int i=1;i<=n;i++)if(tim[i])return 0;
        return 1;
    }else {
        for (int i=len+1;i<=r;i++)tim[a[i]]++;
        for (int i=r+1;i<=n-len;i++){
            tim[a[i]]--;
            if(tim[a[i]]<0)return 0;
        }
        return 1;
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]),tms[a[i]]++;
    int od=0;
    for (int i=1;i<=n;i++)od+=tms[i]&1;
    if(od>=2){
        printf("0\n");
        return 0;
    }
    int i,j;
    for (i=1,j=n;i<=j;i++,j--){
        if(a[i]!=a[j]){len=i-1;break;}
    }
    if(len==-1){
        cout<<1ll*n*(n+1)/2<<endl;
        return 0;
    }
    int lef=len+1,rig=n-len,mid;
    while(lef<=rig){
        mid=lef+rig>>1;
        if(checkl(mid))rig=mid-1;
        else lef=mid+1;
    }
    int minl=lef;

    for (int i=1;i<=n-i+1;i++)swap(a[i],a[n-i+1]);
    lef=len+1,rig=n-len;
    while(lef<=rig){
        mid=lef+rig>>1;
        if(checkl(mid))rig=mid-1;
        else lef=mid+1;
    }
    int maxr=n-lef+1;

    ll ans=1ll*(n-len-minl)*(len+1)+1ll*(maxr-len-1)*(len+1)+1ll*(len+1)*(len+1);
    cout<<ans<<endl;
    return 0;
}