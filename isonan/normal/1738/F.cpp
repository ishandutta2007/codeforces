#include <cstdio>
#include <vector>
#include <algorithm>

int t,n,d[100001];
bool vis[100010];
int f[100010];
int Q(int x){

			printf("? %d\n",x);
			fflush(stdout);
			int ans;
			scanf("%d",&ans);
			return ans;
}
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
void merge(int a,int b){
	a=find(a),b=find(b);
	if(a!=b)f[a]=b;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",d+i),f[i]=0,vis[i]=0;
		std::vector<std::pair<int,int> >vec;
		for(int i=1;i<=n;++i)vec.push_back(std::make_pair(d[i],i));
		std::sort(vec.begin(),vec.end());
		for(int i=n-1;~i;--i){
			int u=vec[i].second;
			if(vis[u])continue;
			vis[u]=1;
			for(int j=1;j<=d[u];++j){
				int tem=Q(u);
				if(vis[tem]){
					merge(u,tem);
					break;
				}
				else{
					vis[tem]=1;
					merge(u,tem);
				}
			}
		}
		printf("! ");
		for(int i=1;i<=n;++i)printf("%d ",find(i));putchar('\n');
		fflush(stdout);
	}
}