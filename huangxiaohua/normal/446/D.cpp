#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,id[505],a[505],it,sb,mp[505];
vector<int> v[505];
long double p,g[105][105],h[505][105],res[105][105],tmp[105][105];

int main() {
	cin>>n>>m>>t;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]){
			id[i]=++it;
			mp[it]=i;
			sb++;
		}
	}
	for(i=1;i<=m;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	vector<vector<long double> >f(605,vector<long double>(605,0));
	for(i=1;i<=n;i++){
		f[i][0]=i;
		if(id[i]){
			f[i][i]=1;f[i][n+id[i]]=1;continue;
		}
		f[i][i]=-1;
		p=1.0/v[i].size();
		for(auto j:v[i]){
			f[i][j]+=p;
		}
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(f[j][i]){
				swap(f[i],f[j]);break;
			}
		}
		p=f[i][i];
		for(j=i;j<=n+sb;j++)f[i][j]/=p;
		for(j=1;j<=n;j++){
			if(i==j)continue;
			p=f[j][i];
			for(k=i;k<=n+sb;k++){
				f[j][k]-=f[i][k]*p;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=sb;j++){
			h[(int)f[i][0]][j]=f[i][n+j];
		}
	}
	for(i=1;i<=sb;i++){
		p=1.0/v[mp[i]].size();
		for(auto j:v[mp[i]]){
			for(k=1;k<=sb;k++){
				g[i][k]+=h[j][k]*p;
			}
		}
		res[i][i]=1;
	}
	t-=2;
	while(t){
		if(t&1){
			memset(tmp,0,sizeof(tmp));
			for(i=1;i<=sb;i++){
				for(j=1;j<=sb;j++){
					for(k=1;k<=sb;k++){
						tmp[i][j]+=g[i][k]*res[k][j];
					}
				}
			}
			memcpy(res,tmp,sizeof(res));
		}
		memset(tmp,0,sizeof(tmp));
		for(i=1;i<=sb;i++){
			for(j=1;j<=sb;j++){
				for(k=1;k<=sb;k++){
					tmp[i][j]+=g[i][k]*g[k][j];
				}
			}
		}
		memcpy(g,tmp,sizeof(g));
		t>>=1;
	}
	long double ans=0;
	for(i=1;i<=sb;i++){
		ans+=h[1][i]*res[i][sb];
	}
	printf("%.20Lf",ans);
	
}