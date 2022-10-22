#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

const int N=5e6+99,inf=1e9;

int n,t,m,a[N],cnt[N];

bool check(int x){
	int sum=0;
	f(i,1,n+1){
		int mn=min(x,cnt[i]);
		sum+=cnt[i]-mn;
		sum-=(x-mn)/2;
	}
	if(sum>0) return 0;
	return 1;
}
void Main(){
	cin>>n>>m;
	f(i,1,n+1) cnt[i]=0;
	f(i,1,m+1){
		int x;
		cin>>x;
		cnt[x]++;
	}
	//eror(check(2));
	//return ;
	int l=0,r=inf;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}