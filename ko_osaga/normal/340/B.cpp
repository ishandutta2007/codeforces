#include <cstdio>
#define v 300
#define t(p,q,r) (x[p]*(y[q]-y[r])+x[q]*(y[r]-y[p])+x[r]*(y[p]-y[q]))
int x[v],y[v];
int main(){
    int n,i,j,k,o,s,r=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
    for(i=0;i<n-1;i++) {
    for(j=i+1;j<n;j++) {
    o=-v;s=v;
    for(k=0;k<n;k++) {
    if(k==i||k==j)continue;
    if(t(i,j,k)>o)o=t(i,j,k);
    if(t(i,j,k)<s)s=t(i,j,k);
    }
    if(o-s>r)r=o-s;
    }}
    printf("%.1lf",(float)r/2.0);
}