#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
#define inf 1000000000000000ll
using namespace std;
typedef long long ll;
struct data{
    ll mans;
    ll mx,my;
};
data operator+(const data&a,const data &b){
    return (data){max(max(a.mans,b.mans),a.mx+b.my),max(a.mx,b.mx),max(a.my,b.my)};
}
    


ll s[200005];
int h[200005];
int d[200005];
ll x[200005],y[200005];
int n;


data t[600005];
void build(int x,int l,int r){
    if(l==r)t[x]=(data){-inf,::x[l],y[l]};
    else{
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        t[x]=t[x<<1]+t[x<<1|1];
    }
}

int bo;
int l1,r1;
data ans;

void query(int x,int l,int r){
    if(l1<=l && r<=r1){
        if(!bo){
            bo=1;
            ans=t[x];
        }else{
            ans=ans+t[x];
        }
    }
    else{
        int mid=l+r>>1;
        if(l1<=mid)query(x<<1,l,mid);
        if(r1>mid)query(x<<1|1,mid+1,r);
    }
}
int main()
{
    int q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)scanf("%d",&d[i]);
    for (int i=1;i<=n;i++)scanf("%d",&h[i]);
    for (int i=n+1;i<=n+n;i++)h[i]=h[i-n];
    s[1]=0;
    for (int i=2;i<=n;i++)s[i]=s[i-1]+d[i-1];
    s[n+1]=s[n]+d[n];
    for (int i=n+2;i<=n+n;i++)s[i]=s[i-1]+d[i-n-1];
    for (int i=1;i<=n+n;i++){
        x[i]=2*h[i]-s[i];
        y[i]=2*h[i]+s[i];
    }
    build(1,1,n+n);

    while(q--){
        int a,b;scanf("%d%d",&a,&b);
        if(a>b){
            l1=b+1,r1=a-1;
        }else{
            l1=b+1,r1=a-1+n;
        }
        bo=0;
        query(1,1,n+n);
        printf("%I64d\n",ans.mans);
    }
    return 0;
}