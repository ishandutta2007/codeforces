#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=1509;
int n,m,a[M][M],b[M][M],d[M],id[M];
bool vis[M],c[M][M];
vector<int>ans,v[M];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i){
		id[i]=i;
		for(int j=1;j<=m;++j){
			scanf("%d",&b[i][j]);
			if(i-1&&b[i-1][j]>b[i][j])d[j]++,v[i].eb(j);
		}
	}
	for(int k=1;k<=m;++k){
		for(int i=1;i<=m;++i){
			if(d[i]||vis[i])continue;
			vis[i]=1;
			for(int x=2;x<=n;++x){
				if(b[x-1][i]<b[x][i]){
					for(auto o:v[x])d[o]--;
					v[x].clear();
				}
			}
			ans.eb(i);
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto o:ans)stable_sort(id+1,id+n+1,[&](const int&l,const int&r){return a[l][o]<a[r][o];});
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[id[i]][j]!=b[i][j]){printf("-1\n");return 0;}
	printf("%d\n",ans.size());
	for(auto o:ans)printf("%d ",o);
	return 0;
}