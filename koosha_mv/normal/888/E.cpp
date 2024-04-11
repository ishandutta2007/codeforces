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
const int N=36,k=30;
ll n,m,p,a[N],b[N],n1,n2,dp1[(1<<18)],dp[(1<<18)],ans,c[(1<<18)],cnt=0;
map<ll,ll> mark;
void solve1(ll mask){
	f(i,0,n1){
		if(mask%(1<<(i+1))>=(1<<i))
			dp1[mask]=(dp1[mask-(1<<i)]+a[i])%m;
	}
}
void solve(ll mask){
	f(i,0,n2){
		if(mask%(1<<(i+1))>=(1<<i))
			dp[mask]=(dp[mask-(1<<i)]+b[i])%m;
	}
}
void add(ll x){
	if(!mark[x]) c[cnt++]=x;
}
ll get_ans(ll x){
	int l=0,r=cnt,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(c[mid]<=x) l=mid;
		else r=mid;
	}
	return c[l];
}
int main(){
	Get(n,m);
	n1=n/2;n2=n-n1;
	f(i,0,n1) get(a[i]);
	f(i,0,n2) get(b[i]);
	f(i,1,(1<<n1)){
		solve1(i);
		maxm(ans,dp1[i]);
		add(dp1[i]);
	}
	c[cnt++]=0;
	sort(c,c+cnt);
	f(i,1,(1<<n2)){
		solve(i);
		maxm(ans,get_ans(m-dp[i]-1)+dp[i]);
	}
	cout<<ans;
}