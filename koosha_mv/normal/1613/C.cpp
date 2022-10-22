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

const int N=1e6+99,inf=2e18;

int n,t,h,a[N];

bool check(int x){
	int ans=0;
	a[n]=inf;
	f(i,0,n){
		ans+=min(x,a[i+1]-a[i]);
	}
	return ans>=h;
}
void Main(){
	cin>>n>>h;
	f(i,0,n) cin>>a[i];
	int l=0,r=inf;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<endl;
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}