#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,w,res,a[606][606];
ll f[606][606],mx[606];
bool y[606][606];

vector<pair<int,int> >q[606];

int main(){
	cin.tie(0);
	cin>>n>>m;
	memset(f,1,sizeof(f));
	for(i=1;i<=m;i++){
		cin>>j>>k>>w;
		f[j][k]=f[k][j]=a[j][k]=a[k][j]=w;
		y[j][k]=y[k][j]=1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(j==k)continue;
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	cin>>t;
	while(t--){
		cin>>j>>k>>w;
		q[j].push_back({k,w});
		q[k].push_back({j,w});
	}
	for(i=1;i<=n;i++)f[i][i]=0;
	for(i=1;i<=n;i++){
		memset(mx,-1,sizeof(mx));
		for(j=1;j<=n;j++){
			for(auto [x,y]:q[i]){
				mx[j]=max(mx[j],y-f[j][x]);
			}
		}
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(!y[j][k])continue;
				if(f[i][j]+a[j][k]<=mx[k]){
					res++;y[j][k]=y[k][j]=0;
				}
			}
		}
	}
	cout<<res;
}