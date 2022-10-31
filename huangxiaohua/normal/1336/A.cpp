#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,l,n,m,t,a[200500],fa[200500],dep[200500],x,y,b[200500];
ll res;
priority_queue<pair<int,int> >q;
vector<int> v[200500];

void dfs(int x,int f){
	a[x]++;
	fa[x]=f;
	dep[x]=dep[f]+1;
	for(auto i:v[x]){
		if(i==f){continue;}
		dfs(i,x);
		a[x]+=a[i];
		b[x]++;
	}
	if(v[x].size()==1&&x!=1){q.push({dep[x]-a[x],x});}
}

int main(){
	scanf("%d%d",&n,&t);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	while(t--){
		auto [x,y]=q.top();q.pop();
		//printf("a%d %d\n",x,y);
		res+=x;
		y=fa[y];
		b[y]--;
		if(!b[y]){q.push({dep[y]-a[y],y});}
	}
	printf("%lld",res);
}