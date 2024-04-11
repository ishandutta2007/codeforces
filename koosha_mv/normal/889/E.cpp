#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99;

int n,k,a[N],dp[N];

int find(int x){
	int l=0,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(a[mid]>x) l=mid;
		else r=mid;
	}
	return r;
}
int calc(int x,int k){
	if(x==n) return k*n;
	int res=0,ans=0,s=k/a[x],ck=k;
	if(s) res=(s-1)*x*a[x]+dp[x];
	ans=s*x*a[x];
	k%=a[x];
	ans+=calc(find(k),k);
	return max(ans,res);
}

main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		if(i) minm(a[i],a[i-1]);
	}
	f_(i,n-1,0){
		dp[i]=calc(i,a[i]-1);
	}
	cout<<dp[0];
}