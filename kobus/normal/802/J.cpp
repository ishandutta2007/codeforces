#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

vector<pair<int,int>>are[1123];
int cost[1123];

void dfs(int v){
	for(int i=0;i<are[v].size();i++){
		if(cost[are[v][i].first]==-1){
			cost[are[v][i].first]=cost[v]+are[v][i].second;
			dfs(are[v][i].first);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;

	for(int i=0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		are[a].pb(make_pair(b,c));
		are[b].pb(make_pair(a,c));
	}
	for(int i=1;i<n;i++){
		cost[i]=-1;
	}
	dfs(0);
	int resp=0;
	for(int i=0;i<n;i++){
		if(cost[i]>resp){
			resp=cost[i];
		}
	}
	cout<<resp<<"\n";

	return 0;
}