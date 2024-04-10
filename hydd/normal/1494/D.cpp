#include<bits/stdc++.h>
using namespace std;
int n,m,v[1100][1100],Ans[1100],tag[1100];
vector<int> vec[1100]; bool ban[1100][1100];
void solve(int f,vector<int> &a){
	if (a.size()==1){
		vec[f].push_back(a.back());
		Ans[a.back()]=v[a.back()][a.back()];
		return;
	}
	int u=++m,mx=0;
	vec[f].push_back(u);
	for (int x:a)
		for (int y:a)
			mx=max(mx,v[x][y]);
	Ans[u]=mx;
	for (int x:a){
		if (ban[u][x]) continue;
		vector<int> tmp;
		for (int y:a)
			if (v[x][y]!=mx){
				mx=max(mx,v[x][y]);
				tmp.push_back(y); ban[u][y]=true;
			}
		solve(u,tmp);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&v[i][j]);
	vector<int> tmp;
	for (int i=1;i<=n;i++) tmp.push_back(i);
	m=n; solve(0,tmp);
	printf("%d\n",m);
	for (int i=1;i<=m;i++) printf("%d ",Ans[i]); putchar('\n');
	printf("%d\n",n+1);
	for (int i=1;i<=m;i++)
		for (int j:vec[i])
			printf("%d %d\n",j,i);
	return 0;
}