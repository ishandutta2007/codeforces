#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int l,r,len;
    void scan(){
        scanf("%d%d",&l,&r); len=r-l;
    }
}x[200];
double w[100][100],ans[200],g[100][100];
int n,f[200],y[200],now,len;
int main(){
    scanf("%d",&n); for (int i=1;i<=n;i++) x[i].scan();
    for (int i=1;i<=n;i++){y[++len]=x[i].l; y[++len]=x[i].r;};
    sort(y+1,y+len+1); f[1]=y[1]; now=1;
    for (int i=2;i<=len;i++) if (y[i]!=y[i-1]) f[++now]=y[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=now;j++) if (f[j]==x[i].l) {x[i].l=j; break;}
        for (int j=1;j<=now;j++) if (f[j]==x[i].r) {x[i].r=j; break;}
    }
    for (int i=1;i<=n;i++){
        memset(ans,0x00,sizeof ans);
        memset(g,0x00,sizeof g);
        for (int j=x[i].l;j<x[i].r;j++){
            memset(w,0x00,sizeof w);
            int l=f[j],r=f[j+1]; w[0][0]=(double)(r-l)/x[i].len;
            int cnt1=0,cnt2=0,cnt=0;
            for (int k=1;k<=n;k++)
                if (k!=i){
                    if (x[k].l>j) cnt2++; 
                    else if (x[k].r<=j) cnt1++;
                    else{
                        cnt++; 
                        double numl=(double)(max(f[x[k].l],l)-f[x[k].l])/x[k].len;
                        double numm=(double)(min(f[x[k].r],r)-max(f[x[k].l],l))/x[k].len;
                        double numr=(double)(f[x[k].r]-min(f[x[k].r],r))/x[k].len;
                        for (int k1=cnt;k1>=0;k1--)
                            for (int k2=cnt-k1;k2>=0;k2--){
                                w[k1][k2]=w[k1][k2]*numm;
                                if (k1) w[k1][k2]+=w[k1-1][k2]*numl;
                                if (k2) w[k1][k2]+=w[k1][k2-1]*numr;
                            }
                    }
                }
            for (int k1=0;k1<=cnt;k1++) 
                for (int k2=0;k2<=cnt-k1;k2++)
                    g[k1+cnt1][k2+cnt2]+=w[k1][k2];
        }
        for (int k1=0;k1<=n;k1++) for (int k2=0;k2<n-k1;k2++) for (int k3=k1+1;k3<=n-k2;k3++) ans[k3]+=g[k1][k2]/(n-k1-k2);
        for (int j=1;j<=n;j++) printf("%.11lf ",(double)ans[j]); printf("\n"); 
    }
    return 0;
}