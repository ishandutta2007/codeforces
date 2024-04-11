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

const int N=1e7+99,lg=31;

int n,t,cnt,ans,a[N],b[N],dp[N][2],nxt[N][2];

void Main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		b[i]=a[i]^i;
	}
	f_(i,n-1,0){
		int res=0,now=0;
		f_(j,lg-1,0){
			int c=bit(b[i],j);
			if(nxt[now][c]==0){
				nxt[now][c]=++cnt;
			}
			if(nxt[now][c^1]){
				maxm(res,dp[nxt[now][c^1]][bit(a[i],j)]);
			}
			now=nxt[now][c];
		}
		res++;
		maxm(ans,res);
		now=0;
		f_(j,lg-1,0){
			int c=bit(b[i],j);
			now=nxt[now][c];
			maxm(dp[now][bit(i,j)],res);
		}
	}
	cout<<ans<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		ans=0;
		f(i,0,cnt+1) nxt[i][0]=nxt[i][1]=dp[i][0]=dp[i][1]=0;
		cnt=0;
	}
}