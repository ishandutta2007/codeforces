#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int n;
int rev[1000005];
int q[1000005];
struct node{
       int l,r,v;
}t[22222222];int ndtot=0;
int head[1000005]={0};
int I;
int add(int x,int l,int r){
    int y=++ndtot;
    t[y]=t[x];t[y].v++;
    if(l!=r){
             int mid=l+r>>1;
             if(I<=mid)t[y].l=add(t[x].l,l,mid);
             else t[y].r=add(t[y].r,mid+1,r);
    }
    return y;
}
int l1,r1;
int que(int x,int l,int r){
    if(!x)return 0;
    if(l1<=l && r<=r1)return t[x].v;
    int mid=l+r>>1,ret=0;
    if(l1<=mid)ret+=que(t[x].l,l,mid);
    if(r1>mid)ret+=que(t[x].r,mid+1,r);
    return ret;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        rev[x]=i;
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&q[i]);
        q[i]=rev[q[i]];
    }
    for (int i=1;i<=n;i++){
        I=q[i];
        head[i]=add(head[i-1],1,n);
    }
    int x=0;
    int m;scanf("%d",&m);
    while(m--){
               int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
               l1=min((a-1+x)%n+1,(b-1+x)%n+1);
               r1=max((a-1+x)%n+1,(b-1+x)%n+1);
               int l2=min((c-1+x)%n+1,(d-1+x)%n+1);
               int r2=max((c-1+x)%n+1,(d-1+x)%n+1);
               printf("%d\n",x=que(head[r2],1,n)-que(head[l2-1],1,n));x++;
    }
    return 0;
}