#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct tree{
    int l,r,size;
}t[30000000];
int len,n,m,A[1001000],B[1001000],lastans,root[1001000];
int f(int k){
    return (k+lastans)%n+1;
}
void insert(int k1,int k2,int k3,int k4){
    t[++len]=t[k1]; t[len].size++;
    if (k2==k3) return; int mid=k2+k3>>1;
    if (mid>=k4){t[len].l=len+1; insert(t[k1].l,k2,mid,k4);} else {t[len].r=len+1; insert(t[k1].r,mid+1,k3,k4);}
}
int find(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return 0;
    if (k2>=k4&&k3<=k5) return t[k1].size;
    int mid=k2+k3>>1; return find(t[k1].l,k2,mid,k4,k5)+find(t[k1].r,mid+1,k3,k4,k5);
}
int main(){
    len=0; scanf("%d",&n);
    for (int i=1;i<=n;i++) {int k1; scanf("%d",&k1); A[k1]=i;}
    for (int i=1;i<=n;i++) scanf("%d",&B[i]);
    for (int i=1;i<=n;i++){root[i]=len+1; insert(root[i-1],1,n,A[B[i]]);}
    scanf("%d",&m); lastans=-1;
    for (;m;m--){
        int k1,k2,k3,k4; scanf("%d%d%d%d",&k1,&k2,&k3,&k4); 
        k1=f(k1); k2=f(k2); if (k1>k2) swap(k1,k2);
        k3=f(k3); k4=f(k4); if (k3>k4) swap(k3,k4); 
        lastans=find(root[k4],1,n,k1,k2)-find(root[k3-1],1,n,k1,k2);
        printf("%d\n",lastans);
    }
    return 0;
}