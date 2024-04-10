#include<bits/stdc++.h>
using namespace std;
#define N 5050
typedef long long ll;
int n,a[N],pre[N][N],suf[N][N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			pre[i][j]=pre[i][j-1]+(a[i]>a[j]);
		}
		suf[i][n+1]=0;
		for(int j=n;j>=i;--j){
			suf[i][j]=suf[i][j+1]+(a[i]>a[j]);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			ans+=pre[j][i-1]*suf[i][j+1];
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}