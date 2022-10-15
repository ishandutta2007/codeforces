#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define int ll
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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int v[2001000];
const ll mod=998244353;
//int limit;
//int seq[2001000];
//ll ksm(ll a,ll b)
//{
//	if(!b)
//		return 1ll;
//	if(b%2)
//		return ksm(a*a%mod,b/2)*a%mod;
//	return ksm(a*a%mod,b/2);
//}
//void NTT(vector<ll> &a,bool type)//0:NTT 1:INTT
//{
//	for(int i=0;i<limit;i++)
//		if(i<seq[i])
//			swap(a[i],a[seq[i]]);
//	for(int mid=1;mid<limit;mid*=2)
//	{
//		ll x=ksm(3,(mod-1)/limit);
//		if(type)
//			x=ksm(x,mod-2);
//		for(int p=mid*2,j=0;j<limit;j+=p)
//		{
//			for(register int k=0;k<mid;k++)
//			{
//				ll y=ksm(x,limit/p*k);
//				ll z1=a[j+k],z2=a[j+k+mid]*y%mod;
//				a[j+k]=(z1+z2)%mod;
//				a[j+k+mid]=(z1-z2+mod)%mod;
//			}
//		}
//	}
//}
//void calc(int m)
//{
//	int bit=0;
//	limit=1;
//	while(limit<=m)
//	{
//		limit*=2;
//		bit++;
//	}
//	for(int i=0;i<limit;i++)
//		seq[i]=((seq[i/2]>>1)|((i&1)<<(bit-1)));
//}
//vector<ll> Convolution(vector<ll> a,vector<ll> b)
//{
////	for(auto x:a)
////		cout<<x<<" ";
////	cout<<"; ";
////	for(auto y:b)
////		cout<<y<<" ";
////	puts("");
//	calc(sz(a)+sz(b));
//	int siz=sz(a)+sz(b);
//	a.resize(limit);
//	b.resize(limit);
//	NTT(a,0);
//	NTT(b,0);
//	vector<ll> c(limit);
//	for(int i=0;i<limit;i++)
//		c[i]=a[i]*b[i]%mod;
//	NTT(c,1);
//	for(int i=0;i<limit;i++)
//		c[i]=c[i]*ksm(limit,mod-2)%mod;
//	return c;
//}
//vector<int> vec[2001000];
//vector<ll> Convall(int l,int r)
//{
////	cout<<l<<" "<<r<<endl;
//	if(r-l+1==2)
//		return Convolution(vec[l],vec[r]);
//	return Convolution(Convall(l,(l+r)/2),Convall((l+r)/2+1,r));
//}
signed main()
{
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		int n,k;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",v+i);
		ll ans=0;
		bool f=0;
		for(int i=n-k+1;i<=n;i++)
			if(v[i]==-1)
				v[i]=0;
			else if(v[i]!=0)
				f=1;
		for(int i=1;i<=n-k;i++)
			if(v[i]>=i)
				f=0;
		if(f)
		{
			puts("0");
			continue;
		}
		ll x=1;
		for(int i=1;i<=k+1;i++)
			x=x*i%mod;
		ll pi=1;
		for(int i=2;i<=n-k;i++)
			if(v[i]==-1)
				pi=pi*(i+k)%mod;
			else if(v[i]==0)
				pi=pi*(k+1)%mod;
		printf("%lld\n",pi*x%mod);
	}
	return 0;
}