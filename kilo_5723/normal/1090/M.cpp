#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int main(){
    int i,n,k;
    int ans,siz;
    scanf("%d%d",&n,&k);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    siz=0; b[siz++]=0;
    for (i=0;i<n-1;i++) if (a[i]==a[i+1])
        b[siz++]=i+1;
    b[siz++]=n;
    ans=0;
    for (i=0;i<siz-1;i++) ans=max(ans,b[i+1]-b[i]);
    printf("%d\n",ans);
    return 0;
}