#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct tree{
    vector<int>x;
    int l,r;
}t[5000000];
struct atom{
    int l,r;
}x[101000];
int len,n,m,f[101000],l[101000],r[101000],num,lim=1e9;
int findfather(int k){
    if (k==f[k]) return k; f[k]=findfather(f[k]); return f[k];
}
void addin(int k1,int k2,int k3,int k4,int k5,int k6){
    if (k2>k5||k3<k4) return;
    if (k2>=k4&&k3<=k5) {t[k1].x.push_back(k6); return;}
    int mid=k2+k3>>1;
    if (t[k1].l==0) t[k1].l=++len; addin(t[k1].l,k2,mid,k4,k5,k6);
    if (t[k1].r==0) t[k1].r=++len; addin(t[k1].r,mid+1,k3,k4,k5,k6);
}
void merge(int k1,int k2){
    k1=findfather(k1); k2=findfather(k2);
    f[k1]=k2; l[k2]=min(l[k2],l[k1]); r[k2]=max(r[k2],r[k1]);
}
void merge(int k1,int k2,int k3,int k4,int k5){
    while (t[k1].x.size()){
        merge(t[k1].x[t[k1].x.size()-1],k5); t[k1].x.pop_back();
    }
    if (k2==k3) return; int mid=k2+k3>>1;
    if (mid>=k4){
        if (t[k1].l) merge(t[k1].l,k2,mid,k4,k5);
    } else if (t[k1].r) merge(t[k1].r,mid+1,k3,k4,k5);
}
int main(){
    scanf("%d",&m); len=1;
    for (;m;m--){
        int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
        if (k1==1){
            num++; l[num]=k2; r[num]=k3; x[num].l=k2; x[num].r=k3; f[num]=num;
            merge(1,-lim,lim,k2,num); merge(1,-lim,lim,k3,num); addin(1,-lim,lim,l[num]+1,r[num]-1,num);  
        } else {
            k3=findfather(k3);// cout<<l[k3]<<" "<<r[k3]<<" "<<x[k2].l<<" "<<x[k2].r<<endl;
            if ((findfather(k2)==k3)||(l[k3]<=x[k2].l&&r[k3]>x[k2].r)) printf("YES\n"); else printf("NO\n");
        }
    }
    return 0;
}