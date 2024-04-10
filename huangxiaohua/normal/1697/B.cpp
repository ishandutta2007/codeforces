#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll p[1005000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>t;
	for(i=1;i<=n;i++)cin>>p[i];
	sort(p+1,p+n+1);
	for(i=1;i<=n;i++)p[i]+=p[i-1];
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<p[n-x+y]-p[n-x]<<'\n';
	}
}