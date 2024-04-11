#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y)
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x)
#define gett(x) scanf("%d",&x)
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

const int N=3e3+99;

int n,t,a[N],dp[N][N];
vector<int> v[N];

void calc(int l,int r){
	int x=a[l];
	dp[l][r]=dp[l+1][r];
	f(i,0,v[x].size()){
		if(v[x][i]>l && v[x][i]<=r){
			maxm(dp[l][r],dp[l+1][v[x][i]-1]+dp[v[x][i]][r]+1);
		}
	}
}
void Main(){
	cin>>n;
	f(i,1,n+1) v[i].clear();
	f(i,1,n+1){ cin>>a[i]; v[a[i]].pb(i); }
	f_(l,n,1)
		f(r,l,n+1)
			calc(l,r);
	cout<<n-1-dp[1][n]<<endl;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
		Main();
}