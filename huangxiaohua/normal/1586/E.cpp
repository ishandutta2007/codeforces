#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300500],it,sb[300500],f[300500],fa[300500],vis[300500],dep[300500],x,y,s1[300500],s2[300500],it1,it2,ans;
map<int,map<int,int> >mp;
vector<pair<int,int> >v[300500];
vector<vector<int> > op;
vector<int> tmp;

void dfs(int x,int ff){
	fa[x]=ff;
	vis[x]=1;
	dep[x]=dep[ff]+1;
	for(auto [i,j]:v[x]){
		if(vis[i]||i==ff)continue;
		dfs(i,x);
	}
}

void dfs2(int x,int ff){
	vis[x]=1;
	int su=0;
	for(auto [i,j]:v[x]){
		if(vis[i]||i==ff)continue;
		dfs2(i,x);
		su+=sb[j];
	}
	ans+=su/2;
	su&=1;
	if(su){
		if(sb[mp[x][ff]]){
			
		}
		else{
			ans++;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back({k,i});
		v[k].push_back({j,i});
		mp[j][k]=mp[k][j]=i;
	}
	dfs(1,0);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d",&x,&y);
		it1=it2=0;
		while(x!=y){
			//printf("a%d %d\n",x,y);
			if(dep[x]>dep[y]){
				s1[++it1]=x;
				sb[mp[x][fa[x]]]^=1;
				x=fa[x];
			}
			else{
				s2[++it2]=y;
				sb[mp[y][fa[y]]]^=1;
				y=fa[y];
			}
		}
		tmp.clear();
		for(j=1;j<=it1;j++){
			tmp.push_back(s1[j]);
		}
		tmp.push_back(x);
		for(j=it2;j>=1;j--){
			tmp.push_back(s2[j]);
		}
		op.push_back(tmp);
	}
	k=0;
	for(i=1;i<=m;i++){
		k+=sb[i];
	}
	if(!k){
		puts("YES");
		for(auto v:op){
			printf("%d\n",(int)v.size());
			for(auto j:v){
				printf("%d ",j);
			}
			puts("");
		}
	}
	else{
		puts("NO");
		memset(vis,0,sizeof(vis));
		dfs2(1,0);
		printf("%d",ans);
	}
}