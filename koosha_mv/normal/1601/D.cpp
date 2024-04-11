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

const int N=1e6+99,inf=1e9+9;

int n,m,d,ans,dp[N],mn[N];
pair<int,int> a[N];
vector<pair<int,int> > v;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>d;
	f(i,0,n){
		int _u,_v;
		cin>>_u>>_v;
		if(_u>=d){
			if(_u>=_v){
				ans++;
				v.pb(mp(_v,_u));
			}
			else a[++m]=mp(_u,_v);
		}
	}
	n=m;
	sort(a+1,a+n+1);
	sort(v.begin(),v.end());
	mn[v.size()]=inf;
	f_(i,int(v.size())-1,0){
		mn[i]=min(mn[i+1],v[i].S);
	}
	f_(i,n,1){
		int l=0,r=n+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(a[i].S<=a[mid].F){
				r=mid;
			}
			else{
				l=mid;
			}
		}
		
		pair<int,int> p=mp(a[i].F,inf);
		int x=upper_bound(v.begin(),v.end(),p)-v.begin();
		if(mn[x]>=a[i].S){
			dp[i]=dp[r]+1;
		}
		maxm(dp[i],dp[i+1]);
	}
	cout<<dp[1]+ans;
}