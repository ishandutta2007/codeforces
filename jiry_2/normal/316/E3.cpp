#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct atom{
    int x[3][3];
}key[210000],A;
struct ansnumber{
    int w,pre;
}f[2010000];
int mo=1e9,n,m,fib[210000],x[210000],a[2010000];
atom operator * (atom k1,atom k2){
    memset(A.x,0x00,sizeof A.x);
    for (int i=1;i<=2;i++)
        for (int j=1;j<=2;j++)
            for (int k=1;k<=2;k++)
                A.x[i][j]=(A.x[i][j]+1ll*k1.x[i][k]*k2.x[k][j]%mo)%mo;
    return A;
}
ansnumber operator * (ansnumber k1,atom k2){
    return (ansnumber){(1ll*k1.w*k2.x[1][1]%mo+1ll*k1.pre*k2.x[2][1])%mo,(1ll*k1.w*k2.x[1][2]%mo+1ll*k1.pre*k2.x[2][2])%mo};
}
ansnumber operator + (ansnumber k1,ansnumber k2){
    return (ansnumber){(k1.w+k2.w)%mo,(k1.pre+k2.pre)%mo};
}
void buildtree(int k1,int k2,int k3){
    if (k2==k3){
        f[k1]=(ansnumber){x[k2],0}; return;
    }
    int mid=k2+k3>>1; buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3);
    f[k1]=f[k1*2+1]*key[mid-k2+1]+f[k1*2];
}
void addin(int k1,int k2,int k3,int k4){
    a[k1]=(a[k1]+k4)%mo; f[k1]=f[k1]+(ansnumber){1ll*k4*fib[k3-k2+1]%mo,1ll*k4*fib[k3-k2]%mo};
}
void pushdown(int k1,int k2,int k3){
    int mid=k2+k3>>1; if (a[k1]==0) return; 
    addin(k1*2,k2,mid,a[k1]); addin(k1*2+1,mid+1,k3,a[k1]); a[k1]=0;
}
ansnumber find(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return (ansnumber){0,0};
    if (k2>=k4&&k3<=k5) return f[k1]; int mid=k2+k3>>1;
    pushdown(k1,k2,k3);
    if (mid<k4) return find(k1*2+1,mid+1,k3,k4,k5);
    if (mid>k5) return find(k1*2,k2,mid,k4,k5);
    int k6=mid-max(k2,k4)+1;
    return find(k1*2+1,mid+1,k3,k4,k5)*key[k6]+find(k1*2,k2,mid,k4,k5);
}
void addin(int k1,int k2,int k3,int k4,int k5,int k6){
    if (k2>k5||k3<k4) return;
    if (k2>=k4&&k3<=k5){addin(k1,k2,k3,k6); return;}
    pushdown(k1,k2,k3); int mid=k2+k3>>1;
    addin(k1*2,k2,mid,k4,k5,k6); addin(k1*2+1,mid+1,k3,k4,k5,k6);
    f[k1]=f[k1*2+1]*key[mid-k2+1]+f[k1*2];
}
void change(int k1,int k2,int k3,int k4,int k5){
    if (k2==k3){f[k1]=(ansnumber){k5,0}; return;}
    int mid=k2+k3>>1; pushdown(k1,k2,k3);
    if (mid>=k4) change(k1*2,k2,mid,k4,k5); else change(k1*2+1,mid+1,k3,k4,k5);
    f[k1]=f[k1*2+1]*key[mid-k2+1]+f[k1*2];
}
void dfs(int k1,int k2,int k3){
    pushdown(k1,k2,k3);
    cout<<k1<<" "<<k2<<" "<<k3<<" "<<f[k1].w<<" "<<f[k1].pre<<" "<<a[k1]<<endl;
    if (k2==k3) return; int mid=k2+k3>>1; dfs(k1*2,k2,mid); dfs(k1*2+1,mid+1,k3);
}
int main(){
    scanf("%d%d",&n,&m); memset(key,0x00,sizeof key); key[0].x[1][1]=1; key[0].x[2][2]=1; key[1].x[1][1]=1; key[1].x[1][2]=1; key[1].x[2][1]=1;
    for (int i=2;i<=n;i++) key[i]=key[i-1]*key[1]; fib[1]=1; fib[2]=1; for (int i=3;i<=n;i++) fib[i]=(fib[i-1]+fib[i-2])%mo;
    for (int i=1;i<=n;i++) fib[i]=(fib[i]+fib[i-1])%mo; 
    for (int i=1;i<=n;i++) scanf("%d",&x[i]); buildtree(1,1,n);
    for (;m;m--){
        int k1,k2,k3; scanf("%d",&k1);
        if (k1==1){
            scanf("%d%d",&k2,&k3); change(1,1,n,k2,k3);
        } else if (k1==2){
            scanf("%d%d",&k2,&k3); printf("%d\n",find(1,1,n,k2,k3).w);
        } else{
            scanf("%d%d%d",&k1,&k2,&k3); addin(1,1,n,k1,k2,k3); //dfs(1,1,n);
        }
    }
    return 0;
}