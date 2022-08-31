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

const int maxn = 1e6+10;
const ll mod = 1e9+7;
const int INF = 1e9+7;
int main()
{
	pii st[10];
	int A[4][3]  = {{1,2,3},{4,5,6},{7,8,9},{INF,0,INF}};

	st[0] = mp(3,1);
	st[1] = mp(0,0);
	st[2] = mp(0,1);
	st[3] = mp(0,2);
	st[4] = mp(1,0);
	st[5] = mp(1,1);
	st[6] = mp(1,2);
	st[7] = mp(2,0);
	st[8] = mp(2,1);
	st[9] = mp(2,2);

	int n;
	sd(n);
	string s;
	cin>>s;
	for(int i = 0;i<=9;i++)
	{
		int pos1 = st[i].F,pos2 = st[i].S;
		vii pos;
		pos.pb(mp(pos1,pos2));
		if(i == s[0]-'0')
			continue;
		bool flag = 0;
		int x1 = st[s[0]-'0'].F,y1=st[s[0]-'0'].S;
		for(int j = 1;j<n;j++)
		{
			int x2 = st[s[j]-'0'].F,y2 = st[s[j]-'0'].S;
			pos1 += x2-x1;
			pos2+=y2-y1;
			if(pos1<0 || pos2<0 || pos1>3 || pos2>2 ||(pos1==3&&pos2==0)||(pos1==3&&pos2==2))
			{
				flag = 1;
				break;
			}
			pos.pb(mp(pos1,pos2));
			x1 = x2;
			y1 = y2;
		}
		if(!flag)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
}