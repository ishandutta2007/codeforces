#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll
#define big __int128

const int N=1e6+99;

int n,k,sum,a[N],b[N];

int G(int a,int b){
	return b*(a-b*b);
}
big R(big x){
	return 1+3*x+3*(x*x);
}
big calc(big a,big b){
	return R(b)-a;
}
big check(big x){
	int ans=0;
	f(i,0,n){
		int l=0,r=a[i];
		while(l+1<r){
			int mid=(l+r)/2;
			if(calc(a[i],mid)<x) l=mid;
			else r=mid;
		}
		ans+=a[i]-r;
		b[i]=r;
	}	
	return ans;
}
void solve(big x){
	big ans=0;
	f(i,0,n){
		int l=0,r=a[i];
		while(l+1<r){
			int mid=(l+r)/2;
			if(calc(a[i],mid)<x) l=mid;
			else r=mid;
		}
		k-=a[i]-r;
		b[i]=r;
	}	
	f(i,0,n){
		if(b[i]<a[i] && calc(a[i],b[i])==x && k<0){
			k++;
			b[i]++;
		}
	}
}
main(){
	cin>>n>>k;
	f(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}
	k=sum-k;
	big l=-4e18,r=4e18;
	while(l+1<r){
		big mid=(l+r)/2;
		if(check(mid)>=k) l=mid;
		else r=mid;
	}
	solve(l);
	f(i,0,n){
		cout<<b[i]<<" ";
	}
}