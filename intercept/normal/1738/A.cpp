#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n;
int a[M];
ll v[2][M];
void work(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int l=0,r=0;
	ll ans=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		if(a[i])v[1][++r]=x;
		else v[0][++l]=x;
		ans+=x;
	}
	sort(v[0]+1,v[0]+l+1,[&](const int&x,const int&y){return x>y;});
	sort(v[1]+1,v[1]+r+1,[&](const int&x,const int&y){return x>y;});
	for(int i=1;i<=l;++i)v[0][i]+=v[0][i-1];
	for(int i=1;i<=r;++i)v[1][i]+=v[1][i-1];	
	ll x=0,y=0;
	x=v[1][min(l,r)]+v[0][min(l-1,r)];
	y=v[0][min(l,r)]+v[1][min(l,r-1)];
	cout<<ans+max(x,y)<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}