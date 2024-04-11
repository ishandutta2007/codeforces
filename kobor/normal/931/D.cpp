#include <bits/stdc++.h>

using namespace std;

vector<int> G[100001];
int p[100001];
int deep[100001];
int zlicz[100001];
int gdp=1;

void deepdfs(int v){
	for(int i=0; i<G[v].size(); i++){
		deep[G[v][i]]=deep[v]+1;
		zlicz[deep[v]+1]++;
		gdp=max(gdp, deep[v]+1);
		deepdfs(G[v][i]);
	}
}

/*void dfs(int v){
	if(G[v].empty()){
		odd.push_back(true);
		return;
	}
	odd[v]=odd[G[v][0]];
	for(int i=1; i<G[v].size(); i++){
		for(int i=0)
	}
	odd[v].push_front(true);
}*/

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, wyn=0;
	cin>>n;
	for(int i=2; i<=n; i++){
		cin>>p[i];
		G[p[i]].push_back(i);
	}
	deep[1]=1;
	zlicz[1]++;
	deepdfs(1);
	for(int i=1; i<=gdp; i++){
		if(zlicz[i]%2){
			wyn++;
		}
	}
	cout<<wyn<<'\n';
	return 0;
}