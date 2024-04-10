#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
#define int ll
using namespace std;
const int M=3e5+9;
int exgcd(int a,int b,int &x,int &y){
	int t=b?exgcd(b,a%b,y,x):a;
	if(!b)x=1,y=0;
	else y-=a/b*x;
	return t;
}
int n,m;
ll sum;
ll a[M],b[M];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		sum+=a[i];
		a[i]=b[i]-a[i];
	}
	sort(a+1,a+n+1,[&](const ll&l,const ll&r){return l>r;});
	for(int i=1;i<=n;++i){
		a[i]+=a[i-1];
	}
	int p=n;
	for(int i=1;i<=n;++i){
		if(a[i]-a[i-1]<0){
			p=i;
			break;
		}
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		int x,y,s,t;
		cin>>x>>y;
		if(n%__gcd(x,y)){
			cout<<-1<<endl;
			continue;
		}
		exgcd(x,y,s,t);
		s*=n/__gcd(x,y);
		t*=n/__gcd(x,y);
		int l=y/__gcd(x,y),r=x/__gcd(x,y),z=l*x;
		s+=l*(t/r);
		t%=r;
		if(t<0)t+=r,s-=l;
		if(s<0){
			cout<<-1<<endl;
			continue;
		}
		int h=(p-t*y)/z;
		ll ans=0;
		for(int j=h-5;j<=h+5;++j){
			if(1ll*t*y+1ll*z*j<=n&&1ll*t*y+1ll*z*j>=0)ans=max(ans,sum+a[t*y+z*j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
5 10
100 50
2 2
1
2 3
*/