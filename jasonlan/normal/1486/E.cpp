#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=5101000;
int n,m;
int dis[maxn];
vector <pair<int,int> > v[maxn];
priority_queue <pair<int,int> > q; 
void dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    q.push(make_pair(0,1));
    while(q.size()){
        int p=q.top().second;
        q.pop();
        for(int i=0,to,w;i<v[p].size();++i){
            to=v[p][i].first;
            w=v[p][i].second;
            if(dis[to]>dis[p]+w){
                dis[to]=dis[p]+w;
                q.push(make_pair(-dis[to],to));
            }
        }
        while(q.size()&&dis[q.top().second]!=-q.top().first)q.pop();
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,x,y,w;i<m;++i){
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back(make_pair(y+w*n,0));
        v[y].push_back(make_pair(x+w*n,0));
        for(int i=1;i<=50;++i){
            v[y+i*n].push_back(make_pair(x,(i+w)*(i+w)));
            v[x+i*n].push_back(make_pair(y,(i+w)*(i+w)));
        }
    }
    dijkstra();
    for(int i=1;i<=n;++i)
        if(dis[i]>=0x3f3f3f3f)printf("-1 ");
        else printf("%d ",dis[i]);
    return 0;
}