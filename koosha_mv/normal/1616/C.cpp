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
#define ld long double

const int N=200;

int n,t,a[N],dp[N][N];

void Main(){
	cin>>n;
	int ans=1;
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,n){
		f(j,i+1,n){
			dp[i][j]=2;
			f(k,0,i){
				//cout<<a[j]-a[i]<<" "<<a[i]-a[k]<<endl;
				if((a[j]-a[i])*(i-k)==(a[i]-a[k])*(j-i)){
					maxm(dp[i][j],dp[k][i]+1);
				}
			}
			maxm(ans,dp[i][j]);
			//cout<<i<<" "<<j<<" : "<<dp[i][j]<<endl;
		}
	}
	cout<<n-ans<<endl;
	
}

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}	
}