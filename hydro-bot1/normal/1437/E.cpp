// Hydro submission #618e0ff6609bbc8c7873469a@1636700151132
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],p[N],ff,b[N],c[N];
void add(int x,int y){for(;x<=n;x+=x&-x)c[x]=max(c[x],y);}
int ask(int x){int ans=0;for(;x;x-=x&-x)ans=max(ans,c[x]);return ans;}
void clear(int x){for(;x<=n;x+=x&-x)c[x]=0;}
int main() {
    int ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]-=i,p[i]=a[i];
    for(int i=1;i<=k;i++)scanf("%d",&b[i]);
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)a[i]=lower_bound(p+1,p+n+1,a[i])-p;
//    for(int i=1;i<=n;i++)cout<<p[i]<<' ';
//    cout<<endl;
    a[0]=0,a[n+1]=n+1;
    b[0]=0,b[k+1]=n+1;
    for(int i=1;i<=k+1;i++){
        if(a[b[i]]<a[b[i-1]]){
            ff=1;
            break;
        }
        int maxx=0;
        for(int j=b[i-1]+1;j<b[i];j++){
            if(a[j]>=a[b[i-1]]&&a[j]<=a[b[i]]){
                int t=ask(a[j])+1;
                maxx=max(maxx,t);
                add(a[j],t);
            }
        }
        for(int j=b[i-1]+1;j<b[i];j++)clear(a[j]);
        ans+=maxx;
    }
    if(ff)puts("-1");
    else printf("%d",n-(k+ans));
    return 0;
}