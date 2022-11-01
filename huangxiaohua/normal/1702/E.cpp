#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,vis[1005000],NMSL[1005000];
vector<int> v[1005000];

void dfs(int x){
	sb++;
	vis[x]=1;
	for(auto i:v[x])if(!vis[i])dfs(i);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			v[i].clear();
			NMSL[i]=0;
			vis[i]=0;
		}
		for(i=1;i<=n;i++){
			cin>>j>>k;
			v[j].push_back(k);
			v[k].push_back(j);
			NMSL[j]++;NMSL[k]++;
		}
		for(i=1;i<=n;i++){
			if(NMSL[i]!=2){
				cout<<"NO\n";goto aaa;
			}
			if(!vis[i]){
				sb=0;dfs(i);
				if(sb&1){
					cout<<"NO\n";goto aaa;
				}
			}
		}
		cout<<"YES\n";
		aaa:;
	}
}