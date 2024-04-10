#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 3e5+10;
const ll mod = 1e9+7;
 
vi g[mn];
int num[2];

void dfs(int x,int p,bool t){
	num[t]++;
	for(int y:g[x])if(y!=p){
		dfs(y,x,t^1);
	}
}
 
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0,0);
	printf("%d\n",min(num[0],num[1])-1);
}