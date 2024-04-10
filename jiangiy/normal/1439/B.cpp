#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100010;
std::vector<int>p[N],ansp;
int n,m,k,deg[N];
bool vis[N];
bool contains(std::vector<int>&a,std::vector<int>&b,int skip){
	int l=0;
	for(int i=0;i<b.size();i++){
		l=std::lower_bound(a.begin()+l,a.end(),b[i])-a.begin();
		if((l==a.size()||a[l]!=b[i])&&b[i]!=skip)return 0;
	}
	return 1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)p[i].clear();
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			p[u].push_back(v);
			p[v].push_back(u);
		}
		for(int i=1;i<=n;i++)std::sort(p[i].begin(),p[i].end());
		for(int i=1;i<=n;i++)deg[i]=p[i].size(),vis[i]=0;
		std::priority_queue<PI,std::vector<PI>,std::greater<PI>>q;
		for(int i=1;i<=n;i++)q.push(MP(deg[i],i));
		int ans=-1,rem=n;
		while(!q.empty()){
			PI t=q.top();
			q.pop();
			int x=t.se,d=t.fi;
			if(vis[x])continue;
			if(d>=k){
				ans=1;
				break;
			}
			if(d==k-1){
				std::vector<int>tmp;
				tmp.push_back(x);
				for(int y:p[x]) if(!vis[y])tmp.push_back(y);
				std::sort(tmp.begin(),tmp.end());
				bool flag=1;
				for(int i=0;i<tmp.size();i++) if(!contains(p[tmp[i]],tmp,tmp[i])){
					flag=0;
					break;
				}
				if(flag){
					ans=2;
					ansp=tmp;
					break;
				}
			}
			vis[x]=1;
			rem--;
			for(int y:p[x]){
				if(!vis[y]){
					deg[y]--;
					q.push(MP(deg[y],y));
				}
			}
		}
		if(ans==1){
			int cnt=0;
			for(int i=1;i<=n;i++)cnt+=!vis[i];
			printf("1 %d\n",cnt);
			for(int i=1;i<=n;i++) if(!vis[i])printf("%d ",i);
			puts("");
		}
		else if(ans==2){
			printf("2\n");
			for(int i=0;i<ansp.size();i++)printf("%d ",ansp[i]);
			puts("");
		}
		else{
			printf("%d\n",-1);
		}
	}
}