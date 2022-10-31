#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,fa[105],dep[105],mx,sb[105],sb2,tmp;
vector<int> v[105];

void dfs(int x){
	for(auto i:v[x]){
		dep[i]=dep[x]+1;
		dfs(i);
	}
	mx=max(mx,dep[x]);
}

void add(int x){
	sb[x]=1;
	if(!fa[x]){return;}
	add(fa[x]);
}

void dfs2(int x,int fa){
	printf("%d ",x);
	if(!tmp){goto aaa;}
	for(auto i:v[x]){
		if(sb[i]){continue;}
		tmp--;
		dfs2(i,x);
		if(!tmp){break;}
	}
	aaa:if(fa){printf("%d ",fa);}
}

void dfs3(int x,int fa){
	printf("%d ",x);
	if(!tmp){goto aaa;}
	for(auto i:v[x]){
		if(sb[i]){continue;}
		tmp--;
		dfs3(i,x);
		if(!tmp){break;}
	}
	aaa:
	if(!sb[x]){printf("%d ",fa);}
	else{
		for(auto i:v[x]){
			if(sb[i]){dfs3(i,x);return;}
		}
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(dep,0,sizeof(dep));
		memset(sb,0,sizeof(sb));
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		for(i=2;i<=n;i++){
			scanf("%d",&fa[i]);
			v[fa[i]].push_back(i);
		}
		if(m==1){printf("0\n1\n");continue;}
		mx=0;
		dfs(1);
		mx=min(mx,m-1);
		for(i=1;i<=n;i++){
			if(dep[i]==mx){sb2=i;add(i);break;}
		}
		/*for(i=1;i<=n;i++){
			printf("%d %d %d\n",i,dep[i],sb[i]);
		}*/
		printf("%d\n",(m-1)*2-mx);
		//printf("a%d\n",sb2);
		tmp=m-mx-1;
		dfs2(1,0);
		for(auto i:v[1]){
			if(sb[i]){dfs3(i,1);}
		}
		puts("");
	}
}