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

const int N=10,S=62;

int n,t,a[N],dp[S][(1<<N)];
pair<int,int> par[S][(1<<N)];
string p[N];
vector<int> v[N][S];
set<pair<int,pair<int,int> > > s;

int is_bit(int mask,int x){
	return 0<(mask&(1<<x));
}
int calc(int x,int mask){
	if(dp[x][mask]!=-1) return dp[x][mask];
	dp[x][mask]=0;
	f(i,0,n){
		if(v[i][x][is_bit(mask,i)]==2*S){
			return dp[x][mask];
		}
	}
	dp[x][mask]=1;
	par[x][mask]=mp(-1,-1);
	f(last,0,S){
		int nmask=0,res=1;
		f(i,0,n){
			int mv=0,now=v[i][x][is_bit(mask,i)];
			f_(j,1,0){
				if(v[i][last][j]<now){
					mv=1;
					nmask^=j*(1<<i);
				}
			}
			res&=mv;
		}
		if(res){
			if(calc(last,nmask)+1>dp[x][mask]){
				par[x][mask]=mp(last,nmask);
				dp[x][mask]=calc(last,nmask)+1;
			}
		}
	}
	return dp[x][mask];
}
void Main(){
	f(i,0,S){
		f(mask,0,(1<<N)){
			dp[i][mask]=-1;
		}
	}
	cin>>n;
	f(i,0,n){
		cin>>p[i];
		f(j,0,S){
			v[i][j].clear();
		}
		f(j,0,p[i].size()){
			v[i][p[i][j]-'A'].pb(j);
		}
		f(j,0,S){
			while(v[i][j].size()<2){
				v[i][j].pb(2*S);
			}
		}
	}
	int x=0,y=0;
	f(i,0,S){
		f(mask,0,(1<<n)){
			if(calc(i,mask)>dp[x][y]){
				x=i,y=mask;
			}
		}
	}
	if(dp[x][y]==0){
		cout<<0<<endl<<endl;
		return ;
	}
	string ans;
	while(x!=-1){
		ans+='A'+x;
		int u=par[x][y].F,v=par[x][y].S;
		x=u,y=v;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	cout<<ans<<endl;
}

int main(){
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
2
ABAB
ABAB
*/