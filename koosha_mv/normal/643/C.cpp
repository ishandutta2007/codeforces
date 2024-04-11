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
#define ld long double

const int N=1e6+99,K=55;
const ll inf=1e18;

int n,t,k;
ld a[N],sum[N],res[N],prt[N],dp[2][N];

void read(){
	cin>>n>>k;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1) dp[0][i]=inf;
	f(i,1,n+1){
		prt[i]=prt[i-1]+1/a[i];
		sum[i]=sum[i-1]+a[i];
		res[i]=res[i-1]+sum[i-1]/a[i];
	}
}
ld calc(int l,int r){
	l--;
	return res[r]-sum[l]*(prt[r]-prt[l])-res[l];
}
void solve(int l,int r,int L,int R,int x){
	if(l>=r) return ;
	int mid=(l+r)/2,Mid=0;
	ld res=inf;
	f(i,L,R){
		if(i<=mid && dp[(x-1)&1][i-1]+calc(i,mid)<res){
			Mid=i;
			res=dp[(x-1)&1][i-1]+calc(i,mid);
		}
	}
	//cout<<mid<<" "<<Mid<<" : "<<res<<endl;
	dp[x&1][mid]=res;
	solve(l,mid,L,Mid+1,x);
	solve(mid+1,r,Mid,R,x);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	setprecision(15);
	read();
	
	f(i,1,k+1){
		dp[i&1][0]=inf;
		solve(1,n+1,1,n+1,i);
	}
	cout<<fixed<<setprecision(15)<<dp[k&1][n]+n;
}