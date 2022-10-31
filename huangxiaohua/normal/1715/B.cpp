#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[100500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		ll n,k,b,s;
		cin>>n>>k>>b>>s;
		for(i=1;i<=n;i++)a[i]=0;
		a[1]=k*b;
		s-=k*b;
		if(s<0){
			cout<<"-1\n";continue;
		}
		for(i=1;i<=n;i++){
			j=min(k-1,s);
			s-=j;
			a[i]+=j;
		}
		if(s){
			cout<<"-1\n";continue;
		}
		for(i=1;i<=n;i++){
			cout<<a[i]<<' ';
		}
		cout<<'\n';
	}
}