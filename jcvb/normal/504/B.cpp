#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;

int n;
int a[300005],b[300005];
/*int minusb[300005];

int les(int *a,int *b){
    for (int i=0;i<n;i++){
        if(a[i]<b[i])return 1;
        if(b[i]<a[i])return 0;
    }
    return 0;
}
int equ(int *a,int *b){
    for (int i=0;i<n;i++){
        if(a[i]!=b[i])return 0;
    }
    return 1;
}
*/
int bit[200005];
void bitupd(int x,int del){for(;x<=n;x+=x&-x)bit[x]+=del;}
int bitque(int x){int ans=0;for(;x;x-=x&-x)ans+=bit[x];return ans;}
int sa[200005],sb[200005];
void trans(int *a,int *to){
    memset(bit,0,sizeof(bit));
    for (int i=1;i<=n;i++)bitupd(i,1);
    for (int i=0;i<n;i++){
        bitupd(a[i]+1,-1);
        to[i]=bitque(a[i]+1);
    }
}
int an[200005];
int vis[200005];
int ans[200005];
int kth(int i){
    int l=1,r=n,mid;
    while(l<=r){
        int mid=l+r>>1;
        if(bitque(mid)>=i)r=mid-1;
        else l=mid+1;
    }
    bitupd(l,-1);
    return l;
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%d",&a[i]);
    for (int i=0;i<n;i++)scanf("%d",&b[i]);
/*  for (int i=0;i<n;i++)minusb[i]=n-1-b[i];
    next_permutation(minusb,minusb+n);


    if(equ(a,minusb)){
        for (int i=0;i<n;i++)printf("%d ",i);
        printf("\n");
        return 0;
    }
    if(les(a,minusb)){
*/      
    trans(a,sa);
    trans(b,sb);
    for (int i=0;i<n;i++)sa[i]+=sb[i];
    if(sa[0]>=n)sa[0]-=n;
    for (int i=n-1;i>=0;i--){
        int bas=n-i;
        if(sa[i]>=bas){
            sa[i]-=bas;
            sa[i-1]++;
        }
    }
    memset(bit,0,sizeof(bit));
    for (int i=1;i<=n;i++)bitupd(i,1);
    for (int i=0;i<n;i++){
        ans[i]=kth(sa[i]+1)-1;
    }
    for (int i=0;i<n;i++)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}