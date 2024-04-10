#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn];
ll calc(int p,int q,int r){
    ll x=p-q,y=q-r,z=r-p;
    return x*x+y*y+z*z;
}
ll ans;
void solve(int a[],int b[],int c[],int u,int v,int w){
    int i,j,k;
    for (i=j=k=0;i<u;i++){
        while (j<v&&b[j]<a[i]) j++;
        if (j==v) break;
        while (k<w&&c[k]<b[j]) k++;
        if (k==w) break;
        while (j+1<v&&calc(a[i],b[j+1],c[k])<=calc(a[i],b[j],c[k])) j++;
        ans=min(ans,calc(a[i],b[j],c[k]));
    }
}
int main(){
    int tt;
    int i,j,k,u,v,w;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d%d%d",&u,&v,&w);
        for (i=0;i<u;i++) scanf("%d",&a[i]); sort(a,a+u);
        for (j=0;j<v;j++) scanf("%d",&b[j]); sort(b,b+v);
        for (k=0;k<w;k++) scanf("%d",&c[k]); sort(c,c+w);
        ans=calc(a[0],b[0],c[0]);
        solve(a,b,c,u,v,w);
        solve(a,c,b,u,w,v);
        solve(b,a,c,v,u,w);
        solve(b,c,a,v,w,u);
        solve(c,a,b,w,u,v);
        solve(c,b,a,w,v,u);
        printf("%lld\n",ans);
    }
    return 0;
}