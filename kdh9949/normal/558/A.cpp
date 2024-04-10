#include<stdio.h>
#include<algorithm>
struct mindol{int pos,val;};
int leftn,rightn,n,vis[111],ans,i,j,p,q;
mindol tree[111];
bool comp(mindol a,mindol b){return a.pos<b.pos;}
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d%d",&tree[i].pos,&tree[i].val);
    std::sort(tree+1,tree+n+1,comp);
    for(i=1;tree[i].pos<0;i++);i--;
    leftn=i;
    rightn=n-i;
    if(leftn<rightn){
        for(i=1;i<=2*leftn+1;i++)ans+=tree[i].val;
    }
    else if(leftn==rightn)
    {
        for(i=1;i<=n;i++)ans+=tree[i].val;
    }
    else{
        for(i=n-2*rightn;i<=n;i++)ans+=tree[i].val;
    }
    printf("%d",ans);
}