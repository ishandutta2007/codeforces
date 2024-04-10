#include<bits/stdc++.h>
using namespace std;
const int N=107;
struct node{
    int l,r,c;
};
bool cmp(node a,node b){
    return a.r<b.r;
}
int n,m,ans[N];
node nd[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        ans[r]=m+1,nd[i]=(node){l,r-1,c};
    }
    nd[0].r=N;//sort(nd+1,nd+m+1,cmp);
    for(int i=1;i<=n;i++){
        if(ans[i])continue;
        //for(int j=1;j<=m;j++)if(nd[j].l<=i&&i<=nd[j].r&&nd[j].c)printf("%d:%d\n",i,j);
        for(int j=1;j<=m;j++)if(nd[j].l<=i&&i<=nd[j].r&&nd[j].c&&nd[j].r<=nd[ans[i]].r)ans[i]=j;
        nd[ans[i]].c--;//printf("i=%d\n",i);for(int i=1;i<=m;i++)printf("%d\n",nd[i].c);
    }//for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    for(int i=1;i<=m;i++)if(nd[i].c){printf("-1");return 0;}
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}