#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5005;
int a[maxn],b[maxn];
ll pre[maxn],suf[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+1ll*a[i]*b[i];
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]+1ll*a[i]*b[i];
    ll res=pre[n];
    for(int i=1;i<=n;i++){
        int l,r;ll sum;
        l=i,r=i,sum=1ll*a[i]*b[i];
        res=max(res,pre[l-1]+suf[r+1]+sum);
        while(l>1&&r<n){
            l--;r++;
            sum+=1ll*a[l]*b[r]+1ll*a[r]*b[l];
            res=max(res,pre[l-1]+suf[r+1]+sum);
        }
        if(i==n)continue;
        l=i,r=i+1,sum=1ll*a[i]*b[i+1]+1ll*a[i+1]*b[i];
        res=max(res,pre[l-1]+suf[r+1]+sum);
        while(l>1&&r<n){
            l--;r++;
            sum+=1ll*a[l]*b[r]+1ll*a[r]*b[l];
            res=max(res,pre[l-1]+suf[r+1]+sum);
        }
    }
    printf("%lld\n",res);
    return 0;
}