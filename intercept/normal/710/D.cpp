#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll __int128_t
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=2e5+9;
ll exgcd(ll a,ll b,ll &x,ll &y){
	int t=b?exgcd(b,a%b,y,x):a;
	if(!b)x=1,y=0;
	else y-=a/b*x;
	return t;
}
int main(){
	ll a1,b1,a2,b2,l,r;
	int r1,r2,r3,r4,r5,r6;
	cin>>r1>>r2>>r3>>r4>>r5>>r6;
	a1=r1,b1=r2,a2=r3,b2=r4,l=r5,r=r6;
	ll x,y;
	ll t=exgcd(a1,a2,x,y);
	if((b2-b1)%t){
		puts("0");
		return 0;
	}
	x*=(b2-b1)/t;
	x=a1*x+b1;
	ll z=a1*a2/t;
	x=(x%z+z)%z;
	r-=x;
	l=max({l,b1,b2});
	l-=x;
	if(r<0&&l>0){
		puts("0");
		return 0;
	}
	if(r>=0&&l<=0){
		long long w=r/z-l/z+1;
		cout<<max(0ll,w);
	}
	else if(r>=0&&l>0){
		long long w=r/z-(l-1)/z;
		cout<<max(0ll,w);
	}
	else if(r<0&&l<=0){
		r=-r;
		l=-l;
		long long w=l/z-(r-1)/z;
		cout<<max(0ll,w);
	}
	return 0;
}