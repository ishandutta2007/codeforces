#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=5e5+10;

void init(){
}

int n;
int col[N]; 
vector<int> V[N];
void dfs(int x){
	for(int i=0;i<V[x].size();++i){
		if(col[V[x][i]]==0){
			col[V[x][i]]=col[x]^3;
			dfs(V[x][i]);
		}
	}
	return;
}
int l[N],r[N];
void MAIN(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&u,&v);
		l[i]=u;r[i]=v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		V[i+i].push_back(i+i-1);
		V[i+i-1].push_back(i+i);
	}
	for(int i=1;i<=n+n;++i){
		if(col[i]==0){
			col[i]=1;
			dfs(i);
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d %d\n",col[l[i]],col[r[i]]);
	}
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}