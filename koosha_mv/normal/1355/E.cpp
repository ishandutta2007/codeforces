#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

ll n,A,R,M,m,sum,ans=1e18,a[N];

void make_m(){
	int l=0,r=1e9+1,mid;
	while(l+1<r){
		int mid=(l+r)/2;
		if(1ll*mid*n<sum) l=mid;
		else r=mid;
	}
	m=r;
}
ll calcf(ll x){
	ll res=0;
	res=R*(sum-x*n);
	int l=-1,r=n,mid;
	while(l+1<r){
		mid=(l+r)/2;
		ll p=a[mid];
		if(mid>0) p-=a[mid-1];
		if(p<=x) l=mid;
		else r=mid;
	}
	if(l>=0)
		res+=(1ll*(l+1ll)*x-a[l])*M;
	return res;
}
void solvef(){
	int l=0,r=m,mid;
	while(l+1<r){
		int mid=(l+r)/2;
		if(calcf(mid-1)>=calcf(mid)) l=mid;
		else r=mid;
	}
	minm(ans,calcf(l));
}
ll calcs(ll x){
	ll res=0;
	res=A*(x*n-sum);
	int l=0,r=n,mid;
	while(l+1<r){
		mid=(l+r)/2;
		int p=a[mid]-a[mid-1];
		if(p<=x) l=mid;
		else r=mid;
	}
	res+=((a[n-1]-a[l])-(n-r)*x)*M;
	return res;
}
void solves(){
	int l=m,r=1e9+2,mid;
	while(l+1<r){
		int mid=(l+r)/2;
		if(calcs(mid-1)>=calcs(mid)) l=mid;
		else r=mid;
	}
	minm(ans,calcs(l));
}
int main(){
	cin>>n>>A>>R>>M;
	M=min(M,R+A);
	f(i,0,n){ cin>>a[i]; sum+=a[i]; }
	sort(a,a+n);
	make_m();
	f(i,1,n) a[i]+=a[i-1];
	solvef();
	solves();
	cout<<ans;
}