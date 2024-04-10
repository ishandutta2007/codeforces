#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e3+10;
pii top[6]={{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
int toi[4][4]={{6,0,1,2},{0,7,3,4},{1,3,8,5},{2,4,5,9}};
int p[7]={1,3,9,27,81,243,729};
bool vis[4][1<<12];
vector<pii>g[4];
bool val[729];
vector<int> r[10];
int su[10];
bool vi[4];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<729;i++){
        int num=0;
        for(int j=0;j<4;j++)g[j].clear();
        memset(vis,0,sizeof(vis));
        for(int j=0;j<6;j++){
            int v=i/p[j]%3;
            for(int k=0;k<v;k++,num++){
                g[top[j].first].push_back({top[j].second,num});
                g[top[j].second].push_back({top[j].first,num});
            }
        }
        queue<pii>q;
        for(int j=0;j<4;j++)q.push({j,0});
        while(q.size()){
            int msk=q.front().second,x=q.front().first;
            q.pop();
            if(vis[x][msk])continue;
            vis[x][msk]=1;
            for(pii p:g[x])if((msk>>p.second)&1^1)q.push({p.first,msk|(1<<p.second)});
        }
        for(int j=0;j<4;j++)val[i]|=(vis[j][(1<<num)-1]);
    }
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c),a--,c--;
        r[toi[a][c]].push_back(b);
    }
    int ans=0;
    for(int i=0;i<10;i++)sort(r[i].begin(),r[i].end());
    for(int i=0;i<10;i++)for(int x:r[i])su[i]+=x;
    for(int i=0;i<729;i++)if(val[i]){
        bool fail=0;
        int cand=0;
        vi[0]=vi[1]=vi[2]=vi[3]=0;
        for(int j=0;j<6;j++){
            int v=i/p[j]%3;
            if(r[j].size()<v){fail=1;break;}
            if(!v)continue;
            vi[top[j].first]=vi[top[j].second]=1;
            if(v%2==r[j].size()%2)cand+=su[j];
            else cand+=su[j]-r[j][0];
        }
        if(fail)continue;
        for(int j=0;j<4;j++)if(vi[j])cand+=su[j+6];
        if(!i)cand=max(max(max(su[6],su[7]),su[8]),su[9]);
        ans=max(ans,cand);
    }
    printf("%d",ans);
}