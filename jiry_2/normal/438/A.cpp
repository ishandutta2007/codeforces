#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
    int next,point;
}b[5000];
int p[2000],n,m,len,a[2000],pd[2000];
long long v[5000],ans;
bool compare(int k1,int k2){
    return v[k1]>v[k2];
}
void ade(int k1,int k2){
    len++; b[len].point=k2; b[len].next=p[k1]; p[k1]=len;
}
void add(int k1,int k2){
    ade(k1,k2); ade(k2,k1);
}
int main(){
    memset(p,0x00,sizeof p);
    len=0;
    memset(b,0x00,sizeof b);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%I64d",&v[i]);
    for (int i=1;i<=m;i++){
        int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
    }
    for (int i=1;i<=n;i++) a[i]=i;
    sort(a+1,a+n+1,compare);
    ans=0;
    memset(pd,0x00,sizeof pd);
    for (int i=1;i<=n;i++){
        long long k=0;
        for (int j=p[a[i]];j;j=b[j].next)
            if (pd[b[j].point]==0)k+=v[b[j].point];
        ans+=k; pd[a[i]]=1;
    }
    printf("%I64d\n",ans);
    return 0;
}