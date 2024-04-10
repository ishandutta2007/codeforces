#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=1e5+9;
const int B=300;
int n,q;
int b[M],a[M],p[M];
void get(int x,int y){
    b[x]=y;
    for(int i=1;i<=B;++i){
        x=p[x];
        y=p[y];
        b[x]=y;
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&p[i]),b[i]=i;
    for(int j=1;j<=B;++j){
        for(int i=1;i<=n;++i){
            b[i]=p[b[i]];
        }
    }
    for(int i=1;i<=n;++i)a[p[i]]=i;
    for(int i=1;i<=q;++i){
        int o;
        scanf("%d",&o);
        if(o==1){
            int x,y;
            scanf("%d%d",&x,&y);
            a[p[x]]=y;
            a[p[y]]=x;
            swap(p[x],p[y]);
            int ax=x,ay=y,bx=x,by=y;
            for(int j=1;j<=B;++j){
                ax=a[ax];
                ay=a[ay];
                bx=p[bx];
                by=p[by];
            }
            get(ax,x);
            get(ay,y);
            get(x,bx);
            get(y,by);
        }
        else{
            int t,k;
            scanf("%d%d",&t,&k);
            while(k>=B){
                t=b[t];
                k-=B;
            }
            while(k){
                t=p[t];
                k--;
            }
            printf("%d\n",t);
        }
    }
    return 0;
}