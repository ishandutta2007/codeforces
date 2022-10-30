#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=2e5+5;
int a[maxn],l[maxn],r[maxn];
int cc[maxn];
int sum[maxn];
int main(){
    int i,n,t;
    int cnt=0,ans,par;
    scanf("%d%d",&n,&t);
    for (i=0;i<n;i++){
        scanf("%d",&a[i]); t=a[i];
        if (!cc[t]){
            cnt++; l[t]=i;
        }
        r[t]=i; cc[t]++;
    }
    for (i=0;i<maxn;i++) if (cc[i]){
        sum[l[i]]++; sum[r[i]]--;
    }
    ans=n; par=0;
    for (i=1;i<n;i++) sum[i]+=sum[i-1];
    for (i=0;i<n;i++){
        par=max(par,cc[a[i]]);
        if (sum[i]==0){
            ans-=par; par=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}