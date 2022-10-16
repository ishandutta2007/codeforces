#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll T,n,i,mx,q,tt,a[N],s[N],sum;
int main(){
	ios::sync_with_stdio(0);
	T=1;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		sum=mx=0;
		for(i=1;i<=n;++i){
			sum+=a[i];
			mx=max(mx,(sum+i-1)/i);
		}
		cin>>q;
		while(q--){
			cin>>tt;
			if(tt<mx)cout<<"-1\n";
			else cout<<(sum+tt-1)/tt<<"\n";
		} 
	}
}