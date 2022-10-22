#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long 
ll ans,j,a[500009],sum,andis;
map <ll,ll> mark;
int main(){
	int n;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	if(a[n]%3!=0){cout<<0;return 0;}
	f(i,1,n){
		if(a[i]==a[n]/3*2){
			//cout<<i<<" "<<a[i]<<endl;
			ans+=mark[a[i]/2];
		}
		mark[a[i]]++;
	}
	cout<<ans;
}