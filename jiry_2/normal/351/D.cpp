#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct atom{
    int l,r,where;
}A[110000];
int n,m,x[110000],pre[110000],pd[110000],a[110000],l[110000],B[110000],ans[110000],num[1100000];
void solve(int k){
    int len=0,now=1,r=1;
    for (int i=k;i;i=pre[i]) {a[++len]=i; pd[i]=1;} a[len+1]=0;
    while (now<=len){
        if (now==len){l[a[now]]=1; return;}
        if (r<=now){
            r++; int k1=a[r]-a[now];
            while (r<len&&a[r+1]-a[r]==k1) r++;
        }
        l[a[now]]=a[r+1]+1; now++;
    }
}
int compare(atom k1,atom k2){
    return k1.r<k2.r;
}
void add(int k1,int k2){
    for (;k1<=n;k1+=k1&(-k1)) B[k1]+=k2;
}
int find(int k1){
    int now=0; for (;k1;k1-=k1&(-k1)) now+=B[k1]; return now;
}
void change(int k1,int k2,int k3,int k4,int k5){
    if (k2==k3){num[k1]=k5; return;}
    int mid=k2+k3>>1;
    if (mid>=k4) change(k1*2,k2,mid,k4,k5); else change(k1*2+1,mid+1,k3,k4,k5);
    num[k1]=min(num[k1*2],num[k1*2+1]);
}
int find(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return n+1;
    if (k2>=k4&&k3<=k5) return num[k1];
    int mid=k2+k3>>1;
    return min(find(k1*2,k2,mid,k4,k5),find(k1*2+1,mid+1,k3,k4,k5));
}
int main(){
    scanf("%d",&n); for (int i=1;i<=n;i++) scanf("%d",&x[i]);
    scanf("%d",&m); for (int i=1;i<=m;i++) {scanf("%d%d",&A[i].l,&A[i].r); A[i].where=i;}
    sort(A+1,A+m+1,compare); 
    for (int i=1;i<=n;i++){
        pre[i]=a[x[i]]; a[x[i]]=i;
    }
    memset(pd,0x00,sizeof pd);
    for (int i=n;i;i--) if (pd[i]==0) solve(i);
    int now=1;
    memset(a,0x00,sizeof a);
    memset(num,0x3f,sizeof num);
    for (int i=1;i<=n;i++){
        if (a[x[i]]){add(a[x[i]],-1); change(1,1,n,a[x[i]],n+1);} add(i,1); a[x[i]]=i; change(1,1,n,i,l[i]);
        while (now<=m&&A[now].r==i){ans[A[now].where]=find(i)-find(A[now].l-1)-(find(1,1,n,A[now].l,i)<=A[now].l)+1; now++;}
    }
    for (int i=1;i<=m;i++) printf("%d\n",ans[i]); return 0;
}