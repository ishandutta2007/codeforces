#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t,p[1000005],fa[1000005],nxt[1000005],vis[1000005];

vector<int> v[1000005];

int main(){
	memset(fa,-1,sizeof(fa));
	memset(nxt,-1,sizeof(nxt));
	
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;m=0;
		for(i=1;i<=n;i++){
			cin>>p[i];
			if(p[i]>i){
				m=i;
			}
			vis[p[i]]=1;
		}
		cout<<m<<'\n';
		
		for(i=1;i<=n;i++){
			v[p[i]].push_back(i);
			if(vis[i])fa[p[i]]=i;
			
			nxt[p[i]]=p[p[i]];
		}
		
		vector<int>res;
		
		for(i=0;i<=n+1;i++){
			//printf("nmsl%d %d %d\n",i,fa[i],nxt[i]);
			if(fa[i]==-1&&nxt[i]!=-1)j=i;
		}
		
		while(1){
			//printf("NMSL%d %d %d\n",j,fa[j],nxt[j]);
			if(fa[j]!=-1)res.push_back(fa[j]);
			for(auto i:v[j]){
				if(i!=fa[j])res.push_back(i);
			}
			if(j==0||j==n+1)break;
			j=nxt[j];
		}
		
		reverse(res.begin(),res.end());
		for(auto i:res){
			cout<<i<<' ';
		}
		cout<<'\n';
		
		for(i=0;i<=n+1;i++){
			fa[i]=-1;
			v[i].clear();
			nxt[i]=-1;
			vis[i]=0;
		}
	}
}