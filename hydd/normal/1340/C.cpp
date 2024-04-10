#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF2=1e18;
deque<pii> q;
int n,m,g,r,d[11000];
int dis[10005][1005];
void bfs(){
    memset(dis,0x3f,sizeof(dis));
    q.push_back(pii(1,g)); dis[1][g]=0;
    while (!q.empty()){
        pii u=q.front(); q.pop_front();
        int i=u.first,j=u.second;
//        printf("%d %d\n",i,j);
		if (i>1&&j>=(d[i]-d[i-1]))
			if (dis[i-1][j-(d[i]-d[i-1])]>dis[i][j]){
				dis[i-1][j-(d[i]-d[i-1])]=dis[i][j];
				q.push_front(pii(i-1,j-(d[i]-d[i-1])));
			}
		if (i<m&&j>=(d[i+1]-d[i]))
			if (dis[i+1][j-(d[i+1]-d[i])]>dis[i][j]){
				dis[i+1][j-(d[i+1]-d[i])]=dis[i][j];
				q.push_front(pii(i+1,j-(d[i+1]-d[i])));
			}
		if (!j){
			if (dis[i][g]>dis[i][j]+1){
				dis[i][g]=dis[i][j]+1;
				q.push_back(pii(i,g));
			}
		}
    }
    
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&d[i]);
	sort(d+1,d+m+1);
	scanf("%d%d",&g,&r);
	bfs();
	ll ans=INF2;
	for (int i=0;i<=g;i++)
		if (dis[m][i]!=0x3f3f3f3f) ans=min(ans,1ll*dis[m][i]*(r+g)+g-i);
	if (ans==INF2) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}