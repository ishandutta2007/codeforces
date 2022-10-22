#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=5e5+99;

int n,k,t,l1,l2,r1,r2;
ll ans;

int inser(){
	return max(min(r1,r2)-l2,0ll);
}
int U(){
	return max(r1,r2)-l1;
}
int C(){
	return U()-inser();
}
ll calc(int x){
	ll res=1ll*max(l2-r1,0ll)*x;
	if(1ll*x*C()>=k) return res+k;
	int h=k-x*C();
	res+=h*2+x*C();
	return res;	
}

main(){
	cin>>t;
	while(t--){
		ans=8e18;
		cin>>n>>k;
		cin>>l1>>r1>>l2>>r2;
		if(l1>l2) swap(l1,l2),swap(r1,r2);
		k-=1ll*inser()*n;
		if(k<=0) cout<<0<<'\n';
		else{
			f(i,1,n+1)
				minm(ans,calc(i));
			cout<<ans<<'\n';
		}
	}
}