#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
const int N=600;
ll x,y,g,C[N][N];
int n,t,a[N],q,s;
ll d,cd,u,v,pr[N],g2,mod=998244353,ans1,ans2,sum,cnt;
ll solve(){
	ll ans=1;
	f(i,0,s){
		ans=ans*C[a[i]][sum]%mod;
		sum-=a[i];
	}
	return ans;
}
int main(){
	f(i,0,N) C[0][i]=1;
	f(i,1,N){
		f(j,1,i+1){
			C[j][i]=(C[j-1][i-1]+C[j][i-1])%mod;
		}
	}
	cin>>d;
	cd=d;
	for(ll i=2;i*i<=cd;i++){
		if(cd%i==0)
			pr[s++]=i;
		while(cd%i==0) cd/=i;
	}
	if(cd>1) pr[s++]=cd;
	cin>>q;
	f(i,0,q){
		fill(a,a+s,0);
		ans1=1,ans2=1;
		Get(u,v);
		g2=__gcd(u,v);
		u/=g2,v/=g2;
		sum=0,cnt=0;
		f(i,0,s){
			while(u%pr[i]==0)
				a[i]++,u/=pr[i];
			sum+=a[i];
		}
		ans1=solve();
		sum=0,cnt=0;
		fill(a,a+s,0);
		f(i,0,s){
			while(v%pr[i]==0)
				a[i]++,v/=pr[i];
			sum+=a[i];
		}
		ans2=solve();
		cout<<(ans1*ans2)%mod<<endl;
	}
}