#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,res,f[1005000],mx;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		mx=-1;
		for(i=1;i<=n;i++){
			f[i]=0;
			ll p=0;
			for(j=1;j<=m;j++){
				cin>>k;
				p+=k;f[i]+=p;
			}
			mx=max(mx,f[i]);
		}
		for(i=1;i<=n;i++){
			if(mx!=f[i]){
				cout<<i<<' '<<mx-f[i]<<'\n';break;
			}
		}
	}
}