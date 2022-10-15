#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("data.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	auto Solve=[&](){
		int n;cin>>n;
		vector<vector<int>> G(n*n);
		vector road(n,vector (n,vector<int>(n)));
		for(int i=0;i<n;i++){
			for(int j=1;i+j<n;j++){
				string s;cin>>s;
				for(int k=0;k<n;k++){
					if(s[k]=='1'){
						road[i][i+j][k]=1;
						int x=min(i*n+k,k*n+i),y=min((i+j)*n+k,k*n+(i+j));
						G[x].emplace_back(y);
						G[y].emplace_back(x);
					}
				}
			}
		}
		
		vector<bool> vis(n*n);
		for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++) vis[i*n+j]=1;
		
		for(int edge=0;edge<n*n;edge++)
		if(!vis[edge]){
			vector<int> q;
			function<void(int)> DFS=[&](int x){
				if(vis[x]) return;
				vis[x]=1,q.emplace_back(x);
				for(auto to:G[x]){
					DFS(to);
				}
			};
			DFS(edge);
			
			if(q.size()!=n-1) continue;
			
			vector<vector<int>> E(n);
			for(auto p:q){
				int x=p/n,y=p%n;
				E[x].emplace_back(y);
				E[y].emplace_back(x);
			}
			bool ok=1;
			for(int k=0;k<n;k++){
				vector<int> dst(n,-1);
				function<void(int,int)> Get_Dist=[&](int x,int fa){
					for(auto to:E[x]){
						if(dst[to]!=-1) continue;
						dst[to]=dst[x]+1;
						Get_Dist(to,x);
					}
				};
				dst[k]=0;
				Get_Dist(k,-1);
				for(int i=0;i<n;i++)
				for(int j=1;i+j<n;j++)
				ok&=((road[i][i+j][k]&&dst[i]==dst[i+j])||(!road[i][i+j][k]&&dst[i]!=dst[i+j]));
			}
			if(ok){
				cout<<"Yes\n";
				for(auto p:q){
					int x=p/n,y=p%n;
					cout<<x+1<<" "<<y+1<<"\n";
				}
				return;
			}
		}
		cout<<"No\n";
	};
	
	int t;cin>>t;
	while(t--) Solve();
	return 0;
}