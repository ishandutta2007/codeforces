#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int x[6];
}num[1000000],A;
int a[1000000],sum[101000][6],n,m,mo=1e9+7,C[6][6];
atom operator + (atom k1,atom k2){
    for (int i=0;i<=5;i++) A.x[i]=(k1.x[i]+k2.x[i])%mo; return A;
}
void addin(int k1,int k2,int k3,int k6){
    for (int i=0;i<=5;i++) num[k1].x[i]=1ll*(sum[k3][i]-sum[k2-1][i])*k6%mo; a[k1]=k6%mo;
}
void pushdown(int k1,int k2,int k3){
    int mid=k2+k3>>1;
    if (a[k1]!=-1){
        addin(k1*2,k2,mid,a[k1]); addin(k1*2+1,mid+1,k3,a[k1]); a[k1]=-1;
    }
}
void insert(int k1,int k2,int k3,int k4,int k5,int k6){
    if (k2>k5||k3<k4) return;
    if (k2>=k4&&k3<=k5){addin(k1,k2,k3,k6); return;}
    pushdown(k1,k2,k3); int mid=k2+k3>>1;
    insert(k1*2,k2,mid,k4,k5,k6); insert(k1*2+1,mid+1,k3,k4,k5,k6);
    num[k1]=num[k1*2]+num[k1*2+1];
}
atom find(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4){
        atom k; memset(k.x,0x00,sizeof k.x); return k;
    }
    if (k2>=k4&&k3<=k5) return num[k1]; int mid=k2+k3>>1; pushdown(k1,k2,k3);
    return find(k1*2,k2,mid,k4,k5)+find(k1*2+1,mid+1,k3,k4,k5);
}
char getin(){
    char ch=getchar(); while (ch!='='&&ch!='?') ch=getchar(); return ch;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        sum[i][0]=sum[i-1][0]+1; int now=i;
        for (int j=1;j<=5;j++){sum[i][j]=(sum[i-1][j]+now)%mo; now=1ll*now*i%mo;}
    }
    for (int i=0;i<=5;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
    }
    memset(a,0xff,sizeof a);
    memset(num,0x00,sizeof num);
    for (int i=1;i<=n;i++) {int k; scanf("%d",&k); insert(1,1,n,i,i,k);}
    for (;m;m--){
        char ch=getin();
        if (ch=='='){
            int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); insert(1,1,n,k1,k2,k3);
        } else {
            int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); atom k=find(1,1,n,k1,k2); 
            int now=1,ans=0;
            for (int i=k3;i>=0;i--){ans=(ans+1ll*C[k3][i]*k.x[i]%mo*now)%mo; now=1ll*now*(1-k1)%mo;}
            printf("%d\n",(ans+mo)%mo);
        }
    }
    return 0;
}