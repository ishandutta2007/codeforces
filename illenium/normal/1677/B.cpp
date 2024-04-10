#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,m,a[N],b[N],g[N],vis[N];
char s[N];
void Solve(){
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n*m;++i){
		g[i]=g[i-1]+(s[i]-'0');
	}
	for(int i=1;i<=n*m;++i){
		a[i]=i<=m?g[i]>0:a[i-m]+(g[i]-g[i-m]>0);
	}
	for(int i=0;i<m;++i)vis[i]=0;
	for(int i=1,now=0;i<=n*m;++i){
		if(s[i]=='1'&&!vis[i%m]){
			vis[i%m]=1;
			++now;
		}
		b[i]=now;
	}
	for(int i=1;i<=n*m;++i){
		cout<<a[i]+b[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}