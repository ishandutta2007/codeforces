#include <cstdio>
#include <vector>
#include <algorithm>

int T,n,b[100001],a[100010],k,t[100001],now;
bool vis[100001],vis2[100001];
std::vector<int>vec[100010];
bool par;
int solve(int x){
	// printf("solve %d\n",x);
	if(x==0)par=1;
	else if(x==n+1)par=0;
	int t=0;
	for(int i=0;i<vec[x].size();++i)if(vis[vec[x][i]])t=vec[x][i];
	for(int i=0;i<vec[x].size();++i)
		if(!vis[vec[x][i]])a[++now]=vec[x][i];
	a[++now]=t;
	if(!par)k+=vec[x].size();
	// printf("%d %d %d %d\n",k,par,vec[x].size(),x);
	par^=1;
	// printf("%d\n",t);
	return t;
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%d",&n);
		for(int i=0;i<=n+1;++i)a[i]=-1,vis[i]=vis2[i]=0,vec[i].clear();
		now=k=0;
		k=0;
		for(int i=1;i<=n;++i){
			scanf("%d",b+i);
			vis[b[i]]=1;
			vec[b[i]].push_back(i);
		}
		int end=-1,st=-1;
		for(int i=0;i<=n+1;++i){
			int p=0;
			for(int v:vec[i])
				if(vis[v]){
					p=v;
					break;
				}
			if(!vec[i].empty()&&!p){
				end=i;
				int now=n;
				for(int v:vec[i])a[now--]=v,vis2[v]=1;
				break;
			}
		}
		if(!vec[0].empty())st=0;
		else st=n+1;
		for(;;){
			st=solve(st);
			if(!st)break;
		}
		// for(int i=0;i<vec[st].size();++i){
		// 	if(vis[vec[st][i]]){
		// 		std::swap(vec[st][i],vec[st].back());
		// 		break;
		// 	}
		// }
		// for(int v:vec[st]){
		// 	a[now++]=v,vis2[v]=1;
		// 	if(st==n+1)++k;
		// }
		// for(int i=1;i<=n;++i)printf("%d ",vis2[i]);putchar('\n');
		// for(int l=1,r=n;l<=r;){
		// 	if(st==0){
		// 		while(l<=n&&vis2[l])++l;
		// 		if(l>r)break;
		// 		int t=0;
		// 		for(int i=0;i<vec[b[l]].size();++i){
		// 			if(vis[vec[b[l]][i]]){
		// 				std::swap(vec[b[l]][i],vec[b[l]].back());
		// 			}
		// 		}
		// 		for(int v:vec[b[l]]){
		// 			a[now++]=v,vis2[v]=1,++k;
		// 		}
		// 	}
		// 	else if(st==n+1){
		// 		while(r&&vis2[r])--r;
		// 		if(l>r)break;
		// 		for(int i=0;i<vec[b[r]].size();++i){
		// 			if(vis[vec[b[r]][i]]){
		// 				std::swap(vec[b[r]][i],vec[b[r]].back());
		// 			}
		// 		}
		// 		for(int v:vec[b[r]])a[now++]=v,vis2[v]=1;
		// 	}
		// 	st=n+1-st;
		// }
		// if(st==0)k+=n-now+1;
		printf("%d\n",k);
		for(int i=1;i<=n;++i)printf("%d ",a[i]);putchar('\n');
	}
}