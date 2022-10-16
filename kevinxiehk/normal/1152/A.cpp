#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a=0,b=0,n,m,t;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t%2==0)a++;
	}
	for(int i=0;i<m;i++){
		cin>>t;
		if(t%2==1)b++;
	}
	int ans=0;
	ans+=min(a,b);
	ans+=min((n-a),(m-b));
	cout<<ans<<endl;
	return 0;
}