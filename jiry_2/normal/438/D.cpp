#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,num[1100000];
long long x[1100000],tot[1100000];
void change(int k){
    tot[k]=tot[k*2]+tot[k*2+1];
    if (x[num[k*2]]>x[num[k*2+1]]) num[k]=num[k*2]; else num[k]=num[k*2+1];
}
void buildtree(int k1,int k2,int k3){
    if (k2==k3){
        num[k1]=k2; tot[k1]=x[k2]; return;
    }
    int mid=k2+k3>>1;
    buildtree(k1*2,k2,mid);
    buildtree(k1*2+1,mid+1,k3);
    change(k1);
}
void changein(int k1,int k2,int k3,int k4,long long k5){
    if (k2==k3){
        tot[k1]=k5; return;
    }
    int mid=k2+k3>>1;
    if (mid>=k4) changein(k1*2,k2,mid,k4,k5); else changein(k1*2+1,mid+1,k3,k4,k5);
    change(k1);
}
int findmax(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return 0;
    if (k2>=k4&&k3<=k5) return num[k1];
    int mid=k2+k3>>1;
    int k6=findmax(k1*2,k2,mid,k4,k5),k7=findmax(k1*2+1,mid+1,k3,k4,k5);
    if (x[k6]>x[k7]) return k6; else return k7;
}
long long findtot(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return 0;
    if (k2>=k4&&k3<=k5) return tot[k1];
    int mid=k2+k3>>1;
    return findtot(k1*2,k2,mid,k4,k5)+findtot(k1*2+1,mid+1,k3,k4,k5);
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%I64d",&x[i]); x[0]=0;
    buildtree(1,1,n);
    for (;m;m--){
        int k1,k2,k3;
        scanf("%d",&k1);
        if (k1==1){
            scanf("%d%d",&k2,&k3); printf("%I64d\n",findtot(1,1,n,k2,k3));
        } else if (k1==3){
            scanf("%d",&k2); long long k4; scanf("%I64d",&k4); x[k2]=k4; changein(1,1,n,k2,k4);
        } else{
            long long k4; scanf("%d%d%I64d",&k2,&k3,&k4);
            int k5=findmax(1,1,n,k2,k3);
            while (x[k5]>=k4){
                x[k5]=x[k5]%k4; changein(1,1,n,k5,x[k5]); k5=findmax(1,1,n,k2,k3);}
        }
    }
    return 0;
}