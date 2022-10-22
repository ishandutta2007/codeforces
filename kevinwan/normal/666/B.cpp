#include <bits/stdc++.h>
using namespace std;

const int mn=3010;
struct quad{
    int q[4];
    bool operator<(const quad &ot)const {return q[0]<ot.q[0];}
};
int kms[4]={0,3,2,1};
typedef pair<int,quad> fml;
vector<int> g[mn];
int dis[mn][mn];
int main()
{
    int n,m,i,j,l;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
    }
    memset(dis,0x3f,sizeof(dis));
    for(i=1;i<=n;i++){
        dis[i][i]=0;
        queue<int>q;
        q.push(i);
        while(q.size()){
            int x=q.front();
            q.pop();
            for(int y:g[x]){
                if(dis[i][y]==0x3f3f3f3f)dis[i][y]=dis[i][x]+1,q.push(y);
            }
        }
    }
    vector<fml> d,k,u;
    for(i=1;i<=n;i++)d.push_back({0,{i}});
    for(i=1;i<4;i++){
        k.clear();
        for(j=1;j<=n;j++){
            u.clear();
            for(fml f:d){
                bool gud=1;
                for(l=0;l<4;l++)if(j==f.second.q[l])gud=0;
                if(!gud)continue;
                f.first+=dis[f.second.q[i-1]][j];
                if(f.first>0x1f1f1f1f)continue;
                f.second.q[i]=j;
                u.push_back(f);
            }
            sort(u.begin(),u.end(),greater<fml>());
            for(l=0;l<min(kms[i],(int)u.size());l++)k.push_back(u[l]);
        }
        d.clear();
        for(auto idk:k)d.push_back(idk);
        
    }
    sort(d.begin(),d.end(),greater<fml>());
    for(int i=0;i<4;i++)printf("%d ",d[0].second.q[i]);
}