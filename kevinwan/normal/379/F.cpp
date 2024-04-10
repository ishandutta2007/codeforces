#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
int anc[mn][19],dep[mn];
inline int go(int a,int b){
    for(int i=0;b;i++,b>>=1)if(b&1)a=anc[a][i];
    return a;
}
inline int lca(int a,int b){
    if(dep[a]>dep[b])a=go(a,dep[a]-dep[b]);
    else b=go(b,dep[b]-dep[a]);
    for(int i=18;i>=0;i--){
        if(anc[a][i]!=anc[b][i])a=anc[a][i],b=anc[b][i];
    }
    if(a==b)return a;
    else return anc[a][0];
}
inline int dis(int a,int b){
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=4;i++)for(int j=0;j<19;j++)anc[i][j]=1;
    dep[2]=dep[3]=dep[4]=1;
    int cur=4;
    int a=2,b=3,d=2;
    while(n--){
        int p;
        scanf("%d",&p);
        cur+=2;
        dep[cur-1]=dep[cur]=dep[p]+1;
        anc[cur-1][0]=anc[cur][0]=p;
        for(int i=1;i<19;i++)anc[cur][i]=anc[cur-1][i]=anc[anc[cur][i-1]][i-1];
        int t;
        if((t=dis(a,cur))>d)d=t,b=cur;
        if((t=dis(b,cur))>d)d=t,a=cur;
        printf("%d\n",d);
    }
}