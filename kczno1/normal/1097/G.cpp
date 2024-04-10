#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5,K=200+5,D=1e9+7;
int k;
struct Data
{
s64 a[K];int n;
s64& operator [](int x)
{
	return a[x]; 
} 
void init()
{
	n=0;a[0]=2;
}
};
void extend(Data &a)
{
	--a[0];
	per(i,a.n,0)(a[i+1]+=a[i])%=D;
	chmin(++a.n,k);
}
void operator +=(Data &a,Data &b)
{
	per(i,a.n,0)
	{
		s64 x=a[i];
		int mj=min(b.n,k-i);
		rep(j,0,mj)(a[i+j]+=x*b[j])%=D;
	}
	chmin(a.n+=b.n,k);
}
Data dp[N];
vector<int>lk[N];		
s64 ans[K];

void dfs(int x,int fr)
{
	dp[x].init();
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs(y,x);
		extend(dp[y]);
		rep(i,0,dp[y].n)ans[i]-=dp[y][i];
		dp[x]+=dp[y];
	//	cerr<<"x="<<x<<endl;
	//	rep(i,0,now.n)cerr<<now[i]<<" ";cerr<<endl;
	//	rep(i,0,dp[x].n)cerr<<dp[x][i]<<" ";cerr<<endl;
	}
	rep(i,0,dp[x].n)ans[i]+=dp[x][i];	
//	cerr<<dp[x].n<<endl;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n;
	cin>>n>>k;
	rep(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].push_back(y);	
		lk[y].push_back(x); 
	}
	dfs(1,0);
	
//	if(n==99999&&k==198)exit(0);
	
	static s64 jie[K],S[K][K];
	jie[0]=1;
	rep(i,1,k)jie[i]=jie[i-1]*i%D;
	rep(i,0,k)
	{
		S[i][0]=i==0;
		rep(j,1,i)S[i][j]=(S[i-1][j]*j+S[i-1][j-1])%D;
	}
	s64 ans=0;
	rep(i,0,k)(ans+=(::ans[i]%D)*S[k][i]%D*jie[i])%=D; 
	cout<<(ans%D+D)%D;	
}