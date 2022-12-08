#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 312345;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define MOD 1000000007


int dis[212345];
vector<int> are[212345];
bool cam[212345];

void dfs(int u,int p){
	if(u==p)dis[u]=0;
	else dis[u]=dis[p]+1;
	for(auto x:are[u]){
		if(x!=p){
			dfs(x,u);
		}
	}
}

int marcam(int u,int p,int d){
	if(u==d){
		cam[u]=1;
		return 1;
	}
	bool top=0;
	for(auto x:are[u]){
		if(x!=p){
			if(marcam(x,u,d))top=1;
		}
	}
	cam[u]=top;
	return top;
}

int discam[212345];

void discamm(int u,int p){
	if(cam[u])discam[u]=0;
	else discam[u]=discam[p]+1;
	for(auto x:are[u]){
		if(x!=p){
			discamm(x,u);
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		are[a].pb(b);
		are[b].pb(a);
	}
	dfs(0,0);
	int num=-1;
	int id=0;
	for(int i=0;i<n;i++){
		if(dis[i]>num){
			num=dis[i];
			id=i;
		}
	}
	int a=id;
	dfs(id,id);
	num=-1;
	id=0;
	for(int i=0;i<n;i++){
		if(i!=a && dis[i]>num){
			num=dis[i];
			id=i;
		}
	}
	int b=id;
	marcam(a,a,b);
	discamm(a,a);
	num=-1;
	id=0;
	for(int i=0;i<n;i++){
		if(i!=a && i!=b && discam[i]>num){
			num=discam[i];
			id=i;
		}
	}
	//cout<<dis[b]<<" "<<discam[id]<<endl;
	cout<<dis[b]+discam[id]<<endl;
	cout<<a+1<<" "<<b+1<<" "<<id+1<<endl;
	
}