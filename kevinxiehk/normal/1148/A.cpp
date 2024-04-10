#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	int sum=c*2;
	sum+=min(a,b)*2;
	sum+=(abs(a-b)!=0);
	cout<<sum<<endl;
	return 0;
}