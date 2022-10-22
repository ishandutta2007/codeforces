#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int a[16][10010];
int g[16][16],sp[16][16];
int sc[16][16][1<<16];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    memset(g,0x3f,sizeof(g));
    memset(sp,0x3f,sizeof(sp));
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=0;k<m;k++){
                g[i][j]=g[j][i]=min(g[i][j],abs(a[i][k]-a[j][k]));
            }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<m-1;k++){
                sp[i][j]=min(sp[i][j],abs(a[i][k]-a[j][k+1]));
            }
    queue<pair<pii,int>>q;
    memset(sc,-1,sizeof(sc));
    for(int i=0;i<n;i++)sc[i][i][1<<i]=0x3f3f3f3f,q.push({{i,i},1<<i});
    while(q.size()){
        int s=q.front().first.first,e=q.front().first.second,msk=q.front().second;
        q.pop();
        for(int i=0;i<n;i++){
            if((msk>>i)&1)continue;
            if(sc[s][i][msk|(1<<i)]==-1)q.push({{s,i},msk|(1<<i)});
            sc[s][i][msk|(1<<i)]=max(sc[s][i][msk|(1<<i)],min(sc[s][e][msk],g[e][i]));
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)ans=max(ans,min(sc[i][j][(1<<n)-1],sp[j][i]));
    printf("%d",ans);
}