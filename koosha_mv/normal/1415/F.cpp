#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
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

const int N=1e6+99,inf=1e15;

int n,a[N],t[N];
pair<int,int> dp[2][N];

int G(int u,int v){
	return abs(u-v);
}
int dist(int l,int r,int x){
	if(r<l) return inf;
	if(l<=x && x<=r) return 0;
	return max(x-r,l-x);
}
int check(int _a,int b){
	f(i,0,2){
		if(dist(dp[i][_a].F,dp[i][_a].S,a[b])<=t[b]-t[_a]){
			return 1;
		}
	}
	return 0;
}
int check(int _a,int b,int c){
	f(i,0,2){
		if(dist(dp[i][_a].F,dp[i][_a].S,a[b])+G(a[b],a[c])<=t[c]-t[_a]){
			return 1;
		}
	}
	return 0;
}

main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	f(i,1,n+1){
		cin>>t[i]>>a[i];
		dp[0][i]=dp[1][i]=mp(1,0);
		int z=min(dist(dp[0][i-1].F,dp[0][i-1].S,a[i]),dist(dp[1][i-1].F,dp[1][i-1].S,a[i]));
		if(z<=t[i]-t[i-1]){
			z=t[i]-t[i-1]-z;
			dp[0][i]=mp(a[i]-z,a[i]+z);
		}
		int mv=0;
		f_(j,i-1,1){
			if(j!=i-1 && G(a[j],a[j+1])>t[j+1]-t[j]){
				break;
			}
			if(G(a[j],a[i])+G(a[j],a[j+1])<=t[j+1]-t[j]) mv=1;
			int s1=0,s2=0;
			if(check(j-1,j)) s1=1;
			if(check(j-1,i,j)) s2=1;
			if(s1 && (s2 || mv)){
				dp[1][i]=mp(a[i-1]-(t[i]-t[i-1]),a[i-1]+(t[i]-t[i-1]));
			}
		}		
		//cout<<i<<" : "<<endl;
		//cout<<dp[0][i].F<<" "<<dp[0][i].S<<endl<<dp[1][i].F<<" "<<dp[1][i].S<<endl<<endl;
	}
	if(dp[0][n].F<=dp[0][n].S || dp[1][n].F<=dp[1][n].S) cout<<"YES";
	else cout<<"NO";
}