#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 1000000007
#define INF INT_MAX - 5000
 

vector<int> are[112];
int n,m;
int comp[112];

void dfs(int x){
	for(int i=0;i<are[x].size();i++){
		int v=are[x][i];
		if(comp[v]==0){
			comp[v]=1;
			dfs(v);
		}
	}
}

 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	int mark=1;

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		are[x].pb(y);
		are[y].pb(x);
	}

	dfs(1);

	for(int i=1;i<=n;i++){
		if(comp[i]==0){
			mark=0;
		}
	}

	if(n==m && mark){
		cout<<"FHTAGN!\n";
	}
	else{
		cout<<"NO\n";
	}

	return 0;
}