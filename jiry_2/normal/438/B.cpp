#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
    int next,point;
}b[300000];
int p[110000],len,m,a[110000],f[110000],pd[110000];
long long v[110000],n,size[110000];
bool compare(int k1,int k2){
    return v[k1]>v[k2];
}
void ade(int k1,int k2){
    len++; b[len].point=k2; b[len].next=p[k1]; p[k1]=len;
}
void add(int k1,int k2){
    ade(k1,k2); ade(k2,k1);
}
int findfather(int k){
    if (f[k]==k) return f[k];
    f[k]=findfather(f[k]);
    return f[k];
}
int main(){
    scanf("%I64d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%I64d",&v[i]);
    memset(p,0x00,sizeof p);
    memset(b,0x00,sizeof b);
    len=0;
    for (int i=1;i<=m;i++){
        int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
    }
    for (int i=1;i<=n;i++) a[i]=i; sort(a+1,a+n+1,compare);
    memset(pd,0x00,sizeof pd);
    for (int i=1;i<=n;i++){f[i]=i; size[i]=1;}
    long long ans=0;
    for (int i=1;i<=n;i++){
        pd[a[i]]=1;
        for (int j=p[a[i]];j;j=b[j].next){
            int k=b[j].point;
            if (pd[k]){
                int k1=findfather(a[i]),k2=findfather(k);
                if (k1!=k2){
                    ans+=size[k1]*size[k2]*v[a[i]];
                    f[k2]=k1; size[k1]+=size[k2];
                }
            }
        }
    }
    printf("%.6lf\n",(double)ans/(double)(n*(n-1)/2));
    return 0;
}