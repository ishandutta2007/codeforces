#include <bits/stdc++.h>
using namespace std;
const int Maxn=80;
typedef long long ll;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int a[Maxn+5][Maxn+5];
ll f[2][Maxn+5];
int n,k;
ll ans=Inf;
int vis[Maxn+5];
vector<int> node[2];
int main(){
	mt19937 mt_rand(time(0));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	ll ans=Inf;
	while(1.0*clock()/CLOCKS_PER_SEC<2.9){
		memset(f,0x3f,sizeof f);
		node[0].clear();
		node[1].clear();
		for(int i=2;i<=n;i++){
			vis[i]=mt_rand()&1;
			node[vis[i]].push_back(i);
		}
		node[0].push_back(1);
		f[0][1]=0;
		for(int t=1;t<=k;t++){
			memset(f[t&1],0x3f,sizeof f[t&1]);
			for(int i=0;i<node[(t&1)^1].size();i++){
				for(int j=0;j<node[t&1].size();j++){
					f[t&1][node[t&1][j]]=min(f[t&1][node[t&1][j]],f[(t&1)^1][node[(t&1)^1][i]]+a[node[(t&1)^1][i]][node[t&1][j]]);
				}
			}
		}
		ans=min(ans,f[0][1]);
	}
	cout<<ans<<endl;
	return 0;
}