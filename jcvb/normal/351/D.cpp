#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n;
int a[100005];map<int,int>nu;int las[100005],pos[100005]={0};
int tot=0;
int b1[100005],b2[100005];
int q;
struct query{
    int l,r;int i;
}qu[100005];
int cmp(const query&a,const query&b){
    return a.r<b.r;
}
void bitupd(int *a,int i,int del){
    for(;i<=n;i+=i&-i)a[i]+=del;
}
int bitque(int *a,int i){
    int ans=0;for(;i;i-=i&-i)ans+=a[i];return ans;
}
int cnt[100005]={0},d[100005];
int start[100005]={0};
int ans[100005];
void add(int i){
    bitupd(b1,las[i]+1,1);
    bitupd(b1,i+1,-1);
    if(cnt[a[i]]==0){
        bitupd(b2,1,1);
        bitupd(b2,i+1,-1);
        start[a[i]]=1;
    }else if(cnt[a[i]]==1){
        bitupd(b2,las[i]+1,1);
        bitupd(b2,i+1,-1);
        d[a[i]]=i-las[i];
    }else{
        if(d[a[i]]==i-las[i]){
            bitupd(b2,las[i]+1,1);
            bitupd(b2,i+1,-1);
        }else{
            bitupd(b2,start[a[i]],-1);
            bitupd(b2,las[las[i]]+1,1);
            start[a[i]]=las[las[i]]+1;
            bitupd(b2,las[i]+1,1);
            bitupd(b2,i+1,-1);
            d[a[i]]=i-las[i];
        }
    }
    cnt[a[i]]++;
}
int ask(int l){
    int x=bitque(b1,l)+1;
    if(bitque(b2,l))x--;
    return x;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]),nu[a[i]];
    for (map<int,int>::iterator it=nu.begin();it!=nu.end();it++)it->second=++tot;
    for (int i=1;i<=n;i++)a[i]=nu[a[i]];
    for (int i=1;i<=n;i++){
        las[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    scanf("%d",&q);
    for (int i=1;i<=q;i++)scanf("%d%d",&qu[i].l,&qu[i].r),qu[i].i=i;
    sort(qu+1,qu+1+q,cmp);
    int cur=1;
    for (int r=1;r<=n;r++){
        add(r);
        while(cur<=q && qu[cur].r==r)ans[qu[cur].i]=ask(qu[cur].l),cur++;
    }
    for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}