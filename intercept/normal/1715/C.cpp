#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,q;
int a[M];
ll get(int x){
	if(a[x]==a[x-1])return n-x+1;
	else return 1ll*x*(n-x+1);
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;++i)ans+=get(i);
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		ans-=get(x);
		if(x<n)ans-=get(x+1);
		a[x]=y;
		ans+=get(x);
		if(x<n)ans+=get(x+1);
		cout<<ans<<endl;
	}
	return 0;
}
/*
5 1

*/