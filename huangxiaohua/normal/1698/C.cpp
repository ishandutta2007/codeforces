#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[200500],sb;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		m=0;sb=0;
		for(i=1;i<=n;i++){
			cin>>k;
			if(k){
				a[++m]=k;
			}
			else sb++;
		}
		unordered_map<ll,ll> vis;
		if(m>=20){
			cout<<"No\n";continue;
		}
		if(sb)a[++m]=0;
		for(i=1;i<=m;i++)vis[a[i]]=1;
		for(i=1;i<=m;i++)for(j=i+1;j<=m;j++)for(k=j+1;k<=m;k++){
			if(!vis[a[i]+a[j]+a[k]]){
				cout<<"No\n";goto aaa;
			}
		}
		cout<<"Yes\n";
		aaa:;
	}
}