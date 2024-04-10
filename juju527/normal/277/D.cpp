#include<bits/stdc++.h>
#define db long double
using namespace std;
const int maxn=1005,maxt=1565;
const db eps=1e-12;
struct node{
    int a,b,s,t;
    db p;
    bool operator <(node i)const{
        return i.p*(1-p)*t<p*(1-i.p)*i.t;
    }
}x[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
db f[maxt],g[maxt];
int main(){
    int n,T;
    n=read();T=read();
    for(int i=1;i<=n;i++){
        int a,b,s,t;
        db p;
        a=read();b=read();s=read();t=read();
        scanf("%Lf",&p);
        x[i]=(node){a,b,s,t,1-p};
    }
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++){
        int a=x[i].a,b=x[i].b,s=x[i].s,t=x[i].t;
        db p=x[i].p;
        for(int j=T;j>=s;j--){
            if(f[j-s]+a-f[j]>eps)f[j]=f[j-s]+a,g[j]=g[j-s]+s;
            else if(fabs(f[j-s]+a-f[j])<eps)g[j]=min(g[j],g[j-s]+s);
            if(j>=s+t){
                if(f[j-s-t]+a+p*b-f[j]>eps)f[j]=f[j-s-t]+a+p*b,g[j]=(g[j-s-t]+s)*(1-p)+j*p;
                else if(fabs(f[j-s-t]+a+p*b-f[j])<eps)g[j]=min(g[j],(g[j-s-t]+s)*(1-p)+j*p);
            }
        }
    }
    db res1=0,res2=0;
    for(int i=1;i<=T;i++)if(f[i]-res1>eps)res1=f[i],res2=g[i];else if(fabs(f[i]-res1)<eps)res2=min(res2,g[i]);
    printf("%.9Lf %.9Lf\n",res1,res2);
    return 0;
}