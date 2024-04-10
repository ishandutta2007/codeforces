#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
int T,n,x,i,a[10005];
int main(){
	ios::sync_with_stdio(0); 
	cin>>T;
	while(T--){
		cin>>n>>x;
		for(i=1;i<=n+n;++i)cin>>a[i];
		sort(a+1,a+n+n+1);
		int fl=0;
		for(i=1;i<=n;++i)if(a[i+n]-a[i]<x)fl=1;
		if(fl)cout<<"NO";
		else cout<<"YES";
		cout<<"\n";
	}
}