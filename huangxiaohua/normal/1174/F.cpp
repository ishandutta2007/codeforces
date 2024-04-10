#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,x,y,t,siz[200500],f[200500],dep[200500],son[200500],tmp,d,cur,d1;
vector<int> v[200500];

void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	siz[x]++;f[x]=fa;
	int tmp=0;
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs(i,x);
		siz[x]+=siz[i];
		if(siz[i]>tmp){son[x]=i;tmp=siz[i];}
	}
}

int main(){
	dep[0]=-1;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	printf("d 1\n");fflush(stdout);scanf("%d",&d1);
	tmp=1;
	for(i=1;i<=17;i++){
		cur=tmp;
		if(d1==dep[cur]){printf("! %d",cur);return 0;}
		while(dep[cur]<d1&&son[cur]){cur=son[cur];}
		printf("d %d\n",cur);fflush(stdout);scanf("%d",&d);
		while(dep[cur]+d!=d1){d--;cur=f[cur];}
		if(dep[cur]==d1){
			printf("! %d",cur);return 0;
		}
		printf("s %d\n",cur);fflush(stdout);scanf("%d",&tmp);
	}
	return 1;
}