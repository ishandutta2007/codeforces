#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
const long long mod=1e9+7;
struct mint
{
	long long value;
	mint(long long x):value(x%mod){}
	mint():value(0){}
	mint operator =(long long b){this->value=b%mod;return *this;}
	long long fixed(){return value;}
	friend mint operator +(const mint &x,const mint &y){mint ans((x.value+y.value)%mod);return ans;}
	friend void operator +=(mint &x,const mint &y){x=x+y;}
	friend mint operator -(const mint &x,const mint &y){mint ans((x.value-y.value+mod)%mod);return ans;}
	friend void operator -=(mint &x,const mint &y){x=x-y;}
	friend mint operator *(const mint &x,const mint &y){mint ans(x.value*y.value%mod);return ans;}
	friend void operator *=(mint &x,const mint &y){x=x*y;}
	friend mint operator ^(const mint &x,const long long &y)
	{
		if(!y)
			return mint(1);
		if(y%2)
			return ((x*x)^(y/2))*x;
		return ((x*x)^(y/2));
	}
	friend void operator ^=(mint &x,const long long &y){x=x^y;}
	friend mint operator /(const mint &x,const mint &y){return x*(y^(mod-2));}
	friend void operator /=(mint &x,const mint &y){x=x/y;}
	friend bool operator <(const mint &x,const mint &y){return x.value<y.value;}
	friend bool operator ==(const mint &x,const mint &y){return x.value==y.value;}
};
mint dpr[1505][1505],sumdpr[1505][1505],p[1505],fact[100100],pr[1505];
mint C(int n,int k)
{
	if(n<k)
		return 0;
	return fact[n]/fact[k]/fact[n-k];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	fact[0]=1;
	for(int i=1;i<100100;i++)
		fact[i]=fact[i-1]*(mint)(i);
	int n,m;
	ll a,b;
	int k;
	cin>>n>>m>>a>>b>>k;
	mint prob=(mint)(a)/(mint)(b);
	for(int i=0;i<=min(m,k);i++)
		p[i]=C(k,i)*(prob^(i))*((1-prob)^(k-i));
	for(int i=0;i<=m;i++)
		for(int j=0;j<i;j++)
			pr[i]+=(p[j]*p[m-i]);
	dpr[0][m]=1;
	sumdpr[0][m]=1;
	for(int i=1;i<=n;i++)
	{
		mint psum=0;
		for(int j=1;j<=m;j++)
		{
			psum+=sumdpr[i-1][j-1]*p[j-1];
			dpr[i][j]+=pr[j]*sumdpr[i-1][m];
			dpr[i][j]-=pr[j]*sumdpr[i-1][m-j];
			dpr[i][j]-=p[m-j]*psum;
		}
		for(int j=1;j<=m;j++)
			sumdpr[i][j]=sumdpr[i][j-1]+dpr[i][j];
	}
	cout<<sumdpr[n][m].fixed()<<endl;
	return 0;
}