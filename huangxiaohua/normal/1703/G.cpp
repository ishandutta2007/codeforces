#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll f[100500][33],a[100500],res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=0;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++){
			f[i][0]=f[i-1][0]+a[i]-m;
			for(j=1;j<=31;j++){
				a[i]/=2;
				f[i][j]=max(f[i-1][j]+a[i]-m,f[i-1][j-1]+a[i]);
			}
			for(j=0;j<=31;j++)res=max(res,f[i][j]);
		}
		cout<<res<<'\n';
	}
}