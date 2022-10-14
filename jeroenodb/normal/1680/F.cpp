#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,f[1005000],no,shit;
vector<int> v[1005000];
void dfs(int x){
	for(auto i:v[x]){
		if(f[i]==-1){
			f[i]=(f[x]^1);dfs(i);
		}
		else if(f[i]==f[x]){
			no++;shit=!f[i];
		}
	}
}
bool chk(){
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	memset(f,-1,n*4+50);
	for(i=1;i<=n;i++)shuffle(v[i].begin(),v[i].end(),rng);
	no=shit=0;
	int nmsl=rng()%n+1;
	f[nmsl]=(rng()&1);
	dfs(nmsl);
	if(no<=2){
		cout<<"YES\n";
		for(i=1;i<=n;i++)cout<<(f[i]^shit);
		cout<<'\n';
	}
	return no<=2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++)v[i].clear();
		for(i=1;i<=m;i++){
			cin>>j>>k;
			v[j].push_back(k);v[k].push_back(j);
		}
		for(int sb=1;sb<=16;sb++){
			if(chk())goto aaa;
		}
		cout<<"NO\n";
		aaa:;
	}
}