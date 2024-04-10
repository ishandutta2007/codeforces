#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,n1,n2,a[10050],sb[66],f[11][10050],g[10050][66],res,vis[66];
vector<int> v[10050];

void fuck(int id,int msk,int tot,int lst){
	int i,j,k;
	if(tot+f[lst][a[id]]==f[0][a[id]]){
		if(!vis[msk])for(i=0;i<b(n2+1);i++){
			g[id][i|msk]|=g[id-1][i];
		}
		vis[msk]=1;
	}
	for(i=1;i<=n2;i++){
		if(b(i)&msk)continue;
		fuck(id,msk|b(i),f[lst][a[sb[i]]]+tot,i);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=0;i<=n;i++){v[i].clear(); memset(g[i],0,sizeof(g[i]));}
		for(i=1;i<=m;i++){cin>>j>>k; v[j].push_back(k); v[k].push_back(j);}
		cin>>n1;
		for(i=1;i<=n1;i++)cin>>a[i];
		cin>>n2; a[0]=1;
		for(i=1;i<=n2;i++)cin>>sb[i];
		for(i=0;i<=n2;i++){
			memset(f[i],-1,n*4+50);
			queue<int> q;
			q.push(a[sb[i]]); f[i][a[sb[i]]]=0;
			while(!q.empty()){
				k=q.front();q.pop();
				for(auto j:v[k]){
					if(f[i][j]==-1){
						f[i][j]=f[i][k]+1;q.push(j);
					}
				}
			}
		}
		g[0][0]=1; res=0;
		for(i=1;i<=n1;i++){
			memcpy(g[i],g[i-1],sizeof(g[i]));
			for(j=1;j<=n2;j++)if(i==sb[j])goto aaa;
			memset(vis,0,sizeof(vis)); vis[0]=1;
			fuck(i,0,0,0);
			if(g[i][b(n2+1)-1]){
				res=n2;break;
			}
			aaa:;
		}
		for(i=0;i<b(n2+1);i++)res=max(res,__builtin_popcount(i)*g[n1][i]);
		cout<<n2-res<<'\n';
	}
}