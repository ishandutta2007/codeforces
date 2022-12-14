#include<bits/stdc++.h>
using namespace std;
#define N 100005
vector<int>son[N];
int k,f1[N],f2[N],f3[N],dep[N],fa[N];
void dfs(int now,int fat){
	f1[now]=0;f2[now]=-1000000000;
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			dfs(T,now);
			if(f1[T]>=f1[now])f2[now]=f1[now],f1[now]=f1[T]+1;
			else f2[now]=max(f2[now],f1[T]+1);
		}
	}
}
void Dfs(int now,int fat){
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			f3[T]=max(f3[now],f1[now]==f1[T]+1?f2[now]:f1[now])+1;
			Dfs(T,now);
		}
	}
}
void DFS(int now,int fat){
	dep[now]=dep[fat]+1;fa[now]=fat;
	for(int i=0,T;i<son[now].size();++i)
		if((T=son[now][i])!=fat)
			DFS(T,now);
}
void solve(int now,int fat){
	dep[now]=dep[fat]+1;
	if(son[now].size()<4){
		if(dep[now]==k+1)return ;
		cout<<"No",exit(0);
	}
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat)solve(T,now);
	}
}
int n,x,y,mx,i;
int main(){
	cin>>n>>k;
	for(i=1;i<n;++i)cin>>x>>y,son[x].push_back(y),son[y].push_back(x);
	dfs(1,0);Dfs(1,0);
	for(i=1;i<=n;++i)mx=max(mx,f1[i]+f3[i]);
	if(mx!=(k<<1))return cout<<"No",0;
	for(i=1;i<=n;++i){
		if(f3[i]==mx)x=i;
	}
	DFS(x,0);
	for(i=1;i<=n;++i){
		if(dep[i]==mx+1){
			y=i;
		}
	}
	for(i=1;i<=mx>>1;++i)y=fa[y];
	if(son[y].size()<3)return cout<<"No",0;
	dep[y]=1;
	for(i=0;i<son[y].size();++i){
		solve(son[y][i],y);
	}
	cout<<"Yes";
}