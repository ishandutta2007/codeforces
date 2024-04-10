#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,t;
ll a[105],sb,l,r,md,sum,n,m,tmp,res=2e18,v[5005000],it;
map<ll,bool> vis;

priority_queue<ll> q;

void dfs0(int dep,ll x,ll y){
	if(!x)return;
	if(dep>n){
		v[++it]=y;
		return;
	}
	while(x){
		dfs0(dep+1,x,y);
		x/=a[dep];y*=a[dep];
	}
}

void dfs(int dep,ll x){
	if(!x)return;
	if(dep>n){
		sum++;return;
	}
	while(x){
		dfs(dep+1,x);
		x/=a[dep];
	}
}

void dfs1(int dep,ll x){
	if(!x)return;
	if(dep>5){
		sum+=upper_bound(v+1,v+it+1,x)-v-1;
		return;
	}
	while(x){
		dfs1(dep+1,x);
		x/=a[dep];
	}
}

int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	
	if(n<=5){
		l=1;r=1e18;
		while(l<=r){
			md=(l+r)/2;
			sum=0;
			dfs(1,md);
			if(sum>=m){
				res=min(res,md);r=md-1;
			}
			else l=md+1;
		}
		cout<<res;
		return 0;
	}
	dfs0(6,1e18,1);
	sort(v+1,v+it+1);
	v[++it]=2e18;
	l=1;r=1e18;
	while(l<=r){
		md=(l+r)/2;
		sum=0;
		dfs1(1,md);
		if(sum>=m){
			res=min(res,md);r=md-1;
		}
		else l=md+1;
	}
	cout<<res;
}