# include<bits/stdc++.h>
using namespace std;
int n,k,ans;
vector<int> vec[1100000];
int dfs(int u,int f){
	if (vec[u].size()==1) return 0;
	vector<int> tmp;
	for (int v:vec[u])
		if (v!=f) tmp.push_back(dfs(v,u)+1);
	sort(tmp.begin(),tmp.end()); int i;
	for (i=(int)tmp.size()-1;i>=1;i--){
		if (tmp[i]+tmp[i-1]<=k) break;
		ans++;
	}
	return tmp[i];
}
int main(){
	scanf("%d%d",&n,&k); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v); vec[v].push_back(u);
	}
	int rt=1; ans=1;
	for(int i=1;i<=n;i++)
		if (vec[i].size()>1){ rt=i; break;}
	dfs(rt,0); printf("%d\n",ans);
	return 0;
}