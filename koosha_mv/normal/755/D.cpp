#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=1e7+9;
ll n,k1,mark[N],tagh=0,loc=1,k=21,p1,p2,p;
ll GET(ll l,ll r){
	ll ans=0;
	l=(1<<k)-l,r=(1<<k)-r;
	p1=(1<<k),p2=(1<<k);
	f_(i,k-1,0){
		if(l>=(1<<i)){
			l-=(1<<i);
			p1-=(1<<i);
			ans+=mark[p1];
		}
		if(r>=(1<<i)){
			r-=(1<<i);
			p2-=(1<<i);
			ans-=mark[p2];
		}
	}
	return ans;
}
void solve(int l,int r){
	if(r>n) r-=n;
	if(l>n) l-=n;
	if(r>l)
		tagh+=GET(l,r);
	else{
		tagh+=GET(l,n+1)+GET(1,r);
	}
}
void add(int x){
	p=0;
	f_(i,k-1,0){
		if(x>=(1<<i)){
			p+=(1<<i);
			x-=(1<<i);
			mark[p]++;
		}
	}
}
int main(){
	cin>>n>>k1;
	if(k1>n/2) k1=(n-k1);
	f(i,0,n){
		solve(loc+1,loc+k1);
		add(loc);
		loc=loc+k1;
		if(loc>n) loc-=n;
		add(loc);
		printf("%I64d%s",tagh+i+2," ");
	}
}