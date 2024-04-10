#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))

void gett()
{
	cerr<< (clock())/(double)cps<<endl;
}

ll powr(ll a, ll b, ll mod)
{
	ll x = 1%mod;
	a %= mod;
	while(b)
	{
		if(b&1)
			x = (x*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return x;
}
ll inv(ll a, ll mod)
{
	return powr(a,mod-2,mod);
}

const int maxn = 55;
int A[maxn][maxn];
bool chkin(int x,int y,int a,int b,int c,int d)
{
	if(x<=b && x>=a && y>=c && y<=d)
		return 1;
	return  0;
}
bool chk(int a,int b,int c,int d,int n)
{
	rep(i,1,n+1)
	rep(j,1,n+1)
	{
		int cnt = 0;
		if(chkin(i,j,a,b,c,d))
			cnt++;
		if(chkin(i,j+1,a,b,c,d))
			cnt++;
		if(chkin(i+1,j,a,b,c,d))
			cnt++;
		if(chkin(i+1,j+1,a,b,c,d))
			cnt++;
		
		if(cnt != A[i][j])
			return 0;

	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	int cnt1 = 0;
	rep(i,1,n+1)
	{
		string s;
		cin>>s;
		rep(j,0,s.length()){
			A[i][j+1] = s[j]-'0';
			if(A[i][j+1] == 1)
				cnt1++;
			}
	}
	if(cnt1 > 4)
		{
			cout<<"No\n";
			return 0;
		}
	rep(i,1,n+1)
	rep(j,1,n+1)
	rep(k,i+1,n+2)
	rep(l,j+1,n+2)
	{
		if(i==1 || j==1 || A[i-1][j-1] == 1)
			if(chk(i,k,j,l,n))
			{
				cout<<"Yes\n";
				return 0;
			}
	}
	cout<<"No\n";
}