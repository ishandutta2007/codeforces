#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int l,r,w;
    bool operator < (node x){
        return w<x.w;
    }
}P[300010];
int minn[4000010],tag[4000010];
void Add(int k,int ad){
    minn[k]+=ad;
    tag[k]+=ad;
}
void Push_Down(int k){
    if(!tag[k]) return;
    Add(k<<1,tag[k]);
    Add(k<<1|1,tag[k]);
    tag[k]=0;
}
void Modify(int k,int l,int r,int x,int y,int ad){
    if(x<=l&&r<=y){Add(k,ad);return;}
    int mid=(l+r)>>1;Push_Down(k);
    if(x<=mid) Modify(k<<1,l,mid,x,y,ad);
    if(mid<y) Modify(k<<1|1,mid+1,r,x,y,ad);
    minn[k]=min(minn[k<<1],minn[k<<1|1]);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1,l,r,w;i<=n;i++){
        scanf("%d %d %d",&P[i].l,&P[i].r,&P[i].w);
    }sort(P+1,P+n+1);
    int ans=2e9;
    for(int i=1,j=1;i<=n;i++){
        Modify(1,1,m-1,P[i].l,P[i].r-1,1);
        if(!minn[1]) continue;
        while(j<=i&&minn[1]>0) Modify(1,1,m-1,P[j].l,P[j].r-1,-1),j++;
        // printf("%d %d\n",j,i);
        ans=min(ans,P[i].w-P[j-1].w);
    }
    printf("%d",ans);
    return 0;
}