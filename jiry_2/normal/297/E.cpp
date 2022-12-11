#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct tree{
    int l,r,size;
}t[3100000];
struct atom{
    int a,b;
    void scan(){
        scanf("%d%d",&a,&b); if (a>b) swap(a,b);
    }
}x[210000];
int n,len,root[210000],A[210000],l[110000],r[1100000];
void insert(int k1,int k2,int k3,int k4){
    len++; t[len]=t[k1]; t[len].size++;
    if (k2==k3) return;
    int mid=k2+k3>>1;
    if (mid>=k4){t[len].l=len+1; insert(t[k1].l,k2,mid,k4);} else {t[len].r=len+1; insert(t[k1].r,mid+1,k3,k4);}
}
int find(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return 0;
    if (k2>=k4&&k3<=k5) return t[k1].size;
    int mid=k2+k3>>1;
    return find(t[k1].l,k2,mid,k4,k5)+find(t[k1].r,mid+1,k3,k4,k5);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        x[i].scan(); A[x[i].a]=x[i].b;
    }
    len=0;
    memset(t,0x00,sizeof t);
    for (int i=1;i<=n*2;i++){
        if (A[i]){root[i]=len+1; insert(root[i-1],1,n*2,A[i]);} else root[i]=root[i-1];
    }
    for (int i=1;i<=n;i++){
        int k1=x[i].a,k2=x[i].b;
        r[i]=find(root[k2-1],1,n*2,k1+1,k2-1)-find(root[k1],1,n*2,k1+1,k2-1);
        l[i]=find(root[n*2],1,n*2,k2+1,n*2)-find(root[k2],1,n*2,k2+1,n*2)+find(root[n*2],1,n*2,1,k1-1)-find(root[k2],1,n*2,1,k1-1)+find(root[k1-1],1,n*2,1,k1-1)+find(root[k1-1],1,n*2,k2+1,n*2);
    }
//  for (int i=1;i<=n*2;i++) cout<<A[i]<<" "; cout<<endl;
//  for (int i=1;i<=n;i++) cout<<x[i].a<<" "<<x[i].b<<" "<<l[i]<<" "<<r[i]<<endl;
    long long ans=1ll*n*(n-1)*(n-2)/3;
    for (int i=1;i<=n;i++){
        ans-=2ll*l[i]*r[i]+1ll*(n-1-l[i]-r[i])*(l[i]+r[i]);
    }
    cout<<ans/2<<endl; return 0;
}