#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
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
 
const int N=1e6+99,inf=2e6;
 
int n,t,sum,a[N],A[N],B[N];
 
void calc(int p){
	A[p]=B[p]=0;
	if(p==0){
		f(i,1,n){
			A[p]+=a[0]*a[i];
			B[p]+=a[0]+a[i];
		}
	}
	else{
		A[p]=A[p-1];
		B[p]=B[p-1];
		A[p]+=a[p]*a[n-1];
		B[p]+=a[p]+a[n-1];
		A[p]-=a[0]*a[p];
		B[p]-=a[0]+a[p];
	}
}
int solve(int t){
	int mn=4e18;
	f(i,0,n-1) minm(mn,A[i]+t*B[i]);
	return mn;
}
void Main(){
	sum=0;
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	f(i,0,n-1) calc(i);
	int l=-inf,r=inf;
	if(solve(l)>solve(l+1) || solve(r)<solve(r+1)){
		cout<<"INF\n";
		return ;
	}
	while(l+1<r){
		int mid=(l+r)>>1;
		if(solve(mid)<solve(mid+1)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<(ll)solve(r)<<'\n';
}
 
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll tt;
	cin>>tt;
	while(tt--){
		Main();
	}
}
/*
1
8
-27 -22 -22 -20 -17 0 13 26
*/