#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,res,x,y,used[100500],tmp,son[100500];
vector<int> v[100500];

void dfs(int a,int b){
	used[a]=1;
	int i;
	for(i=0;i<v[a].size();i++){
		if(used[v[a][i]]){continue;}
		dfs(v[a][i],b);
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		res=0;
		for(i=1;i<=n;i++){
			v[i].clear();used[i]=son[i]=0;
		}
		for(i=1;i<=k;i++){
			scanf("%d%d",&x,&y);
			if(x==y){continue;}
			res++;
			son[x]++;son[y]++;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		for(i=1;i<=n;i++){
			if(son[i]==1){dfs(i,i);}
		}
		
		for(i=1;i<=n;i++){
			if(used[i]||v[i].size()==0){continue;}
			dfs(i,i);
			res++;
		}
		printf("%d\n",res);
	}
}