#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
char str[100005];
struct node{
    int cnt[26];
    int tag;
}t[300000];
int l1,r1,v;
int ans[26];
void cover(int x,int v,int l){
    t[x].tag=v;
    for (int i=0;i<26;i++)t[x].cnt[i]=0;
    t[x].cnt[v]=l;
}
void pd(int x,int l){
    if(~t[x].tag){
        cover(x<<1,t[x].tag,l-(l>>1));
        cover(x<<1|1,t[x].tag,l>>1);
        t[x].tag=-1;
    }
}
void cov(int l,int r,int x){
    if(l1<=l && r<=r1){
        cover(x,v,r-l+1);
    }else{
        pd(x,r-l+1);
        int mid=l+r>>1;
        if(l1<=mid)cov(l,mid,x<<1);
        if(r1>mid)cov(mid+1,r,x<<1|1);
        for (int i=0;i<26;i++)t[x].cnt[i]=t[x<<1].cnt[i]+t[x<<1|1].cnt[i];
    }
}
void que(int l,int r,int x){
    if(l1<=l && r<=r1){
        for (int i=0;i<26;i++)ans[i]+=t[x].cnt[i];
    }else{
        pd(x,r-l+1);
        int mid=l+r>>1;
        if(l1<=mid)que(l,mid,x<<1);
        if(r1>mid)que(mid+1,r,x<<1|1);
    }
}
void walk(int l,int r,int x){
    if(l==r){
        for (int i=0;i<26;i++)if(t[x].cnt[i]){putchar('a'+i);break;}
    }else{
        pd(x,r-l+1);
        int mid=l+r>>1;
        walk(l,mid,x<<1);
        walk(mid+1,r,x<<1|1);
    }
}
void build(int l,int r,int x){
    t[x].tag=-1;
    if(l==r)t[x].cnt[str[l]-'a']=1;
    else{
        int mid=l+r>>1;
        build(l,mid,x<<1);
        build(mid+1,r,x<<1|1);
        for (int i=0;i<26;i++)t[x].cnt[i]=t[x<<1].cnt[i]+t[x<<1|1].cnt[i];
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    build(1,n,1);
    while(m--){
        int l,r;
        scanf("%d%d",&l1,&r1);l=l1,r=r1;
        memset(ans,0,sizeof(ans));
        que(1,n,1);
        int tm=0,p;
        for (int i=0;i<26;i++)if(ans[i]&1)tm++,p=i;
        if(tm>1)continue;
        int cur=l;
        for (int i=0;i<26;i++)if(ans[i]>1){
            int q=ans[i]>>1;
            l1=cur,r1=cur+q-1,v=i;
            cov(1,n,1);
            r1=r-(cur-l),l1=r1-q+1;
            cov(1,n,1);
            cur+=q;
        }
        if(tm==1){
            l1=r1=l+r>>1;
            v=p;
            cov(1,n,1);
        }
    }
    walk(1,n,1);
    putchar('\n');
    return 0;
}