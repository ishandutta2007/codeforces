#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,f[1005000];
ll res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		for(i=1;i<=n;i++){
			cin>>j>>k;
			res+=j+j+k+k;
			f[i]=max(j,k);
		}
		sort(f+1,f+n+1);
		for(i=1;i<n;i++){
			res-=f[i]*2;
		}
		cout<<res<<'\n';
	}
}