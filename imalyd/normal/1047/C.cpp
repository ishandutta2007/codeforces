//Problem C
#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
const int N=300005,M=15000005,P=1000000;
int a[N],mn[P],cnt[P],ans=-1,n,Cnt[P],vis[M],pri[P],tot;
void add(int v,int p){//printf("%d %d\n",v,p);
    ++Cnt[p];
    if(mn[p]==-1||v<mn[p])mn[p]=v,cnt[p]=1;
    else if(v==mn[p])++cnt[p];
}
void init();
int main(){
    init();
    memset(mn,-1,sizeof(mn));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int v=sqrt(a[i]);
        for(int j=1;j<=tot&&pri[j]<=v;j++)if(a[i]%pri[j]==0){
            int c=0;
            while(a[i]%pri[j]==0)a[i]/=pri[j],++c;
            add(c,j);
        }
        if(a[i]!=1)add(1,lower_bound(pri+1,pri+tot+1,a[i])-pri);
    }
    for(int i=1;i<=tot;i++){
        if(Cnt[i]<n)cnt[i]=n-Cnt[i];
        if(cnt[i]&&cnt[i]!=n&&(ans==-1||cnt[i]<ans))ans=cnt[i];
    }//printf("%d\n",cnt[2]);
    printf("%d",ans);
    return 0;
}
void init(){
    for(int i=2;i<M;i++){
        if(!vis[i])pri[++tot]=i;
        for(int j=1;j<=tot&&i*pri[j]<M;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0)break;
        }
    }//for(int i=1;i<=10;i++)printf("%d ",pri[i]);
}