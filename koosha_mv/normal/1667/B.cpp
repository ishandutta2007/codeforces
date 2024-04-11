#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

int n,t,m,a[N],dp[N],res[N],fn1[N];

void add1(int x, int val){ for(x+=2;x<n+10;x+=x&-x) maxm(fn1[x],val); }
int get1(int x) { int res=-inf; for (x+=2;x>0;x-=x&-x) maxm(res,fn1[x]); return res; }

void upd(int x,int val,int p){
	maxm(res[x],val);
	add1(x,val-p);
}
void Main(){
	vector<int> vec;
	cin>>n;
	f(i,0,n+10) fn1[i]=res[i]=-inf,a[i]=0;
	vec.pb(0);
	f(i,1,n+1){
		cin>>a[i];
		a[i]+=a[i-1];
		vec.pb(a[i]);
	}
	//dbga(a,0,n+1);
	sort(all(vec));
	f(i,0,n+1) a[i]=lower_bound(all(vec),a[i])-vec.begin()+1;
	//dbga(a,0,n+1);
	upd(a[0],0,0);
	int prt=0;
	f(i,1,n+1){
		dp[i]=res[a[i]];
		maxm(dp[i],i+get1(a[i]-1));
		maxm(dp[i],prt-i);
		upd(a[i],dp[i],i);
		maxm(prt,dp[i]+i);
	}
	cout<<dp[n]<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
3
1 2 -3
4
0 -2 3 -4
5
-1 -2 3 -1 -1
6
-1 2 -3 4 -5 6
7
1 -1 -1 1 -1 -1 1
*/