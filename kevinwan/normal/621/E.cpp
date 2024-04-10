#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll num[100],luse[100],t[100],mun[100],ans[100],idk[100];
ll n,b,k,x;
void mult(ll a[],ll b[],ll c[]){
    memset(t,0,sizeof(t));
    int i,j;
    for(i=0;i<x;i++)for(j=0;j<x;j++)t[(i+j)%x]+=b[i]*c[j]%mod;
    for(i=0;i<x;i++)a[i]=t[i]%mod;
}
void iter(ll a[],int st,int len){
    int i,j;
    for(i=0;i<len;i++,st=st*10%x){
        memset(mun,0,sizeof(mun));
        for(j=0;j<10;j++)mun[j*st%x]+=num[j];
        mult(a,a,mun);
    }
}
int main()
{
    set<int>v;
    for(int i=0;i<1000;i++)v.insert(i);
    int i;
    scanf("%lld%lld%lld%lld",&n,&b,&k,&x);
    for(i=0;i<n;i++){
        int y;
        scanf("%d",&y);
        num[y%x]++;
    }
    ll p=1;
    memset(luse,-1,sizeof(luse));
    ll cyc,beg,st;
    for(i=0;1;i++,p=p*10%x){
        if(luse[p]!=-1){
            cyc=i-luse[p];
            beg=luse[p];
            st=p;
            break;
        }
        else luse[p]=i;
    }
    ans[0]=1;
    iter(ans,1,min(beg,b));
    if(b<=beg){
        printf("%lld",ans[k]);
        return 0;
    }
    b-=beg;
    idk[0]=1;
    iter(idk,st,cyc);
    int tim=b/cyc;
    for(;tim;tim>>=1,mult(idk,idk,idk))if(tim&1)mult(ans,ans,idk);
    iter(ans,st,b%cyc);
    printf("%lld",ans[k]);
}