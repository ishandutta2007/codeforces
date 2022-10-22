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

const int N=1e6+99,inf=1e9;

int n,t,d,a[N],dp[N],pd[N],seg[N],fen[N];

void Main(){
	vector<int> vec;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
	}
	cin>>d;
	f(i,1,n+1){
		a[i]-=d;
		//a[i]+=a[i-1];
		vec.pb(a[i]);
	}
	int last=1;
	f(i,1,n+1){
		pd[i]=-N;
		dp[i]=dp[i-1];
		maxm(dp[i],dp[max(0ll,i-2)]+1);
		if(i>1 && a[i]+a[i-1]>=0){
			maxm(dp[i],dp[max(0ll,i-3)]+2);
			//eror(dp[max(0ll,i-3)]+2);
			//eror(dp[i]);
			maxm(pd[i],dp[max(0ll,i-3)]+2);
			if(i>2 && a[i]+a[i-1]>=0 && a[i-1]+a[i-2]>=0 && a[i-2]+a[i-1]+a[i]>=0){
				maxm(dp[i],pd[i-1]+1);
				maxm(pd[i],pd[i-1]+1);
			}
		}
		//cout<<dp[i]<<" "<<pd[i]<<endl;
	}
	cout<<dp[n]<<'\n';
}

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}	
}