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
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define ld double

const int N=85,inf=1e9;

int n,t,now,a[N],L[N],R[N];
vector<int> mt;
ld dp[N][N],ans[N][N];

ld E(int x,int s,int t){
	ld l=max(L[x],s),r=min(R[x],t);
	if(r<l) return 0;
	return (r-l)/(R[x]-L[x]);
}
void Add(int x,int s,int t){
	ld p0=E(x,0,s),p1=E(x,s,t),p2=E(x,t,inf);
	for(int i=now;i>=0;i--){
		for(int j=now-i;j>=0;j--){
			int k=now-i-j;
			dp[i+1][j]+=p0*dp[i][j];
			dp[i][j+1]+=p2*dp[i][j];
			dp[i][j]*=p1;
		}
	}
	now++;
}
void solve(int l,int r,int s,int t){
	if(l+1==r){
		for(int i=now;i>=0;i--){
			for(int j=now-i;j>=0;j--){
				int k=now-i-j;
				dp[i][j]=dp[i][j]*E(l,s,t);
				ans[l][i]+=dp[i][j]/(k+1);
				ans[l][i+k+1]-=dp[i][j]/(k+1);
			}
		}
		return ;
	}
	ld pd[N][N];	
	int mid=(l+r)>>1,Max=n;

	now=n-(r-l);
	f(i,0,Max) f(j,0,Max) pd[i][j]=dp[i][j];
	f(i,mid,r) Add(i,s,t);
	
	solve(l,mid,s,t);
	
	now=n-(r-l);
	f(i,0,Max) f(j,0,Max) dp[i][j]=pd[i][j];
	
	f(i,l,mid) Add(i,s,t);
	
	solve(mid,r,s,t);	
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>L[i]>>R[i];
		mt.pb(L[i]);
		mt.pb(R[i]);
	}
	sort(mt.begin(),mt.end());
	mt.resize(unique(mt.begin(),mt.end())-mt.begin());
	f(i,1,mt.size()){
		f(i,0,N) f(j,0,N) dp[i][j]=0; dp[0][0]=1; now=0;
		
		solve(0,n,mt[i-1],mt[i]);
	}
	f(i,0,n){
		f(j,0,n){
			if(j>0) ans[i][j]+=ans[i][j-1];
			cout<<fixed<<setprecision(9)<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}