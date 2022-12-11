#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long long x[110000];
int n,A,cf,cm,w[110000],a[110000];
long long m;
int compare(int k1,int k2){
    return w[k1]<w[k2];
}
int main(){
    scanf("%d%d%d%d%I64d",&n,&A,&cf,&cm,&m);
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    for (int i=1;i<=n;i++) a[i]=i;
    sort(a+1,a+n+1,compare);
    for (int i=1;i<=n;i++) x[i]=x[i-1]+w[a[i]];
//  for (int i=1;i<=n;i++) cout<<x[i]<<" "; cout<<endl;
    long long anss=-100; int where1=0,where2=0,fin=0;
    for (int now=1;now<=n+1;now++){
        long long k1=1ll*A*(n-now+1)-(x[n]-x[now-1]);
        if (k1>m) continue;
        if (now==1){
            printf("%I64d\n",1ll*A*cm+1ll*n*cf);
            for (int i=1;i<=n;i++) printf("%d ",A); printf("\n"); return 0;
        }
    //  cout<<"solve "<<now<<endl;
        int l=1,r=now,ans=0;
        while (l<r){
            int mid=(l+r)>>1;
            long long k2=1ll*w[a[mid]]*mid-x[mid];
            if (k1+k2<=m){
                ans=mid; l=mid+1;
            } else r=mid;
        }
    //  cout<<ans<<endl;
        long long k2=1ll*w[a[ans]]*ans-x[ans],rem=m-k1-k2;
        int k3=min(1ll*A,w[a[ans]]+rem/ans);
        long long noww=1ll*(n-now+1)*cf+1ll*k3*cm; //cout<<k3<<" "<<noww<<endl;
        if (noww>anss){
            anss=noww; where1=now; where2=ans; fin=k3;
        }
    }
    printf("%I64d\n",anss);
    for (int i=where1;i<=n;i++) w[a[i]]=A;
    for (int i=1;i<=where2;i++) w[a[i]]=fin;
    for (int i=1;i<=n;i++) printf("%d ",w[i]); printf("\n");
    return 0;
}