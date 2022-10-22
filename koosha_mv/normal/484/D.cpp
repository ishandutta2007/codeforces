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

const int N=1e6+99;

int n,t,a[N];
vector<int> v0,v1;
set<pair<ll,int> > s0,s1;
ll dp[N];

void del0(int x){
	s0.erase(mp(dp[x-1]-a[x],x));
}
void del1(int x){
	s1.erase(mp(dp[x-1]+a[x],x));	
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		dp[i]=dp[i-1];
		while(v0.size() && a[v0.back()]>=a[i]){
			del0(v0.back());
			v0.pop_back();
		}
		while(v1.size() && a[v1.back()]<=a[i]){
			del1(v1.back());
			v1.pop_back();
		}
		if(s0.size()) maxm(dp[i],(*s0.rbegin()).F+a[i]);
		if(s1.size()) maxm(dp[i],(*s1.rbegin()).F-a[i]);
		v0.pb(i);
		v1.pb(i);
		s0.insert(mp(dp[i-1]-a[i],i));
		s1.insert(mp(dp[i-1]+a[i],i));
	}
	cout<<dp[n];
}