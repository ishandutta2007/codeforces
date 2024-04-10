#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[1050];

vector<pair<int,int> >v[1050];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			v[i].clear();
			f[i]=f[i-1]^i;
		}
		for(i=1;i<=n;i++){
			cin>>j>>k;
			v[k-j+1].push_back({j,k});
		}
		for(i=1;i<=n;i++){
			for(auto [l,r]:v[i]){
				k=(f[r]^f[l-1]);
				cout<<l<<' '<<r<<' '<<k<<'\n';
				for(j=k;j<=n;j++)f[j]^=k;
			}
		}
	}
}