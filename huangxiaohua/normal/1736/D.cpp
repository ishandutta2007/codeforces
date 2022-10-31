#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,p[1000050];
string a;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>a;
		a="$"+a;
		k=0; m=0;
		for(i=1;i<=n+n;i++){
			k^=(a[i]-'0');
		}
		if(k){
			cout<<"-1\n";continue;
		}
		for(i=2;i<=n+n;i+=2){
			if(a[i]!=a[i-1]){
				if(a[i]!=a[p[m]])p[++m]=i;
				else p[++m]=i-1;
			}
		}
		cout<<m<<' ';
		for(i=1;i<=m;i++){cout<<p[i]<<' ';}cout<<'\n';
		for(i=1;i<=n+n;i+=2){cout<<i<<' ';}cout<<'\n';
	}
}