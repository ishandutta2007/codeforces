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

const int N=1e6+99;

int n,t,a[N],s[N],b[N],p[N],last[N];
vector<int> d[N];
vector<int> v[N],mv[N],dp[N];
ll ans;
set<pair<int,int> > S;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	s[1]=1;
	f(i,2,N){
		if(!s[i]){
			s[i]=i;
			for(int j=i*2;j<N;j+=i){
				if(!s[j]){
					s[j]=i;
				}
			}
		}
	}
	f(i,2,N){
		d[i]=d[i/s[i]];
		d[i].pb(s[i]);
	}
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
	}
	f(i,1,n+1){
		char c;
		cin>>c;
		b[i]=(c=='*');
	}
	f(i,1,n+1){
		int x=a[i];
		f(j,0,d[x].size()){
			v[d[x][j]].pb(i);
			dp[d[x][j]].pb(i);
		}
	}
	f(i,2,N){
		f_(j,v[i].size()-1,0){
			dp[i][j]=v[i].size();
			if(b[v[i][j]]==0){
				dp[i][j]=j;
			}
			else{
				if(j+1<dp[i].size() && dp[i][j+1]+1<dp[i].size()){
					dp[i][j]=dp[i][dp[i][j+1]+1];
				}
			}
		}
		v[i].pb(n+1);
		mv[i]=v[i];
		p[i]=dp[i].size()-1;
	}
	f_(i,n,1){
		int x=a[i];
		f(j,0,d[x].size()){
			int u=d[x][j];
			if(p[u]!=dp[u].size()-1)
				S.erase(mp(v[u][dp[u][p[u]+1]],u));
			S.insert(mp(v[u][dp[u][p[u]]],u));
			p[u]--;
		}
		if(S.size()){
			pair<int,int> P=*S.begin();	
			ans+=P.F-i;
		}
		else{
			ans+=n-i+1;
		}
	}
	cout<<ans;
}