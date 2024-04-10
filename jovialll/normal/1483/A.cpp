#include<bits/stdc++.h>
using namespace std;
#define py puts("Yes");
#define pn puts("No");
#define N 200005
int T,n,a[N],i,j,fl,m,c[N],x,k[N],ans[N];
vector<int>f[N];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=m;++i)f[i].clear();
		for(i=1;i<=n;++i)c[i]=0;
		for(i=1;i<=m;++i){
			cin>>k[i];
			for(j=1;j<=k[i];++j)cin>>x,f[i].push_back(x);
			if(k[i]==1)++c[x];
		}fl=0;
		for(i=1;i<=n;++i)if(c[i]>(m+1>>1)){fl=1,cout<<"NO\n";break;}
		if(fl)continue;
		for(i=1;i<=m;++i){
			if(k[i]==1)ans[i]=f[i][0];
		}
		for(i=1;i<=m;++i){
			if(k[i]!=1){
				for(j=0;j<f[i].size();++j){
					if(c[f[i][j]]<(m+1>>1)){ans[i]=f[i][j];++c[f[i][j]];break;}
				}
			}
		}
		cout<<"YES\n";
		for(i=1;i<=m;++i)cout<<ans[i]<<' ';cout<<"\n";
	}
}