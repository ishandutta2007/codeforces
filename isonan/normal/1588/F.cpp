#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

int n,p[200001],que[200001][3],q;
int P[200001];
long long a[200001];
int bel[200001],st[200001],end[200001],top;
const int B=450;
int siz[B<<2][B<<2|1];
long long V[B<<2|1];
bool vis[200001],in[200001],qd[200001];
std::pair<int,int> tem[B<<2|1];
std::vector<int>vec[B<<2|1];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",a+i),a[i]+=a[i-1];
	for(int i=1;i<=n;++i)scanf("%d",p+i);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
		for(int j=0;j<3;++j)
			scanf("%d",&que[i][j]);
	for(int i=1;i<=q;i+=B){
		int r=std::min(i+B-1,q);
		int tt=0;
		memset(qd,0,sizeof qd);
		for(int k=i;k<=r;++k){
			if(que[k][0]==3){
				vis[que[k][1]]=vis[que[k][2]]=1;
			}
			else if(que[k][0]==2){
				qd[que[k][1]]=1;
			}
			else if(que[k][0]==1){
				tem[++tt]=std::make_pair(que[k][1]-1,-k);
				tem[++tt]=std::make_pair(que[k][2],k);
			}
		}
		std::sort(tem+1,tem+tt+1);
		for(int i=1;i<=n;++i)in[i]=bel[i]=0;
		for(int i=1;i<=n;++i)if(!vis[i])in[p[i]]=1;
		top=0;
		for(int i=1;i<=n;++i)
			if(!in[i]){
				int tem=i;
				st[++top]=i;
				V[top]=0;
				vec[top].clear();
				bool bb=0;
				for(;;){
					bel[tem]=top;
					if(vis[tem])break;
					tem=p[tem];
				}
				end[top]=tem;
			}
		for(int i=1;i<=n;++i)
			if(!bel[i]&&qd[i]){
				int tem=i;
				st[++top]=i;
				V[top]=0;
				vec[top].clear();
				bool bb=0;
				for(;;){
					bel[tem]=top;
					tem=p[tem];
					if(tem==i)break;
				}
				end[top]=tem;
			}
		for(int i=1;i<=n;++i)if(bel[i])vec[bel[i]].push_back(i);
		memset(siz,0,sizeof siz);
		for(int i=1;i<=top;++i){
			vec[i].push_back(n+1);
			for(int j=0,now=1;j<vec[i].size();++j)
				while(now<=tt&&tem[now].first<vec[i][j]){
					int u=tem[now++].second;
					if(u<0)siz[i][r+u]-=j;
					else siz[i][r-u]+=j;
				}
		}
		for(int k=i;k<=r;++k){
			if(que[k][0]==1){
				int R=que[k][2],L=que[k][1];
				long long ans=a[R]-a[L-1];
				for(int l=1;l<=top;++l)
					ans+=1ll*V[l]*siz[l][r-k];
				printf("%lld\n",ans);
			}
			else if(que[k][0]==2){
				int u=bel[que[k][1]],x=que[k][2];
				int tem=u;
				do{
					V[tem]+=1ll*x;
					tem=bel[p[end[tem]]];
				}while(tem!=u);
			}
			else{
				std::swap(p[que[k][1]],p[que[k][2]]);
			}
		}
		long long All=0;
		for(int i=1;i<=n;++i){
			All+=V[bel[i]];
			a[i]+=All;
		}
		memset(vis,0,sizeof vis);
	}
}