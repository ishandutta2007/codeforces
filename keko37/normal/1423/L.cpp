//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define all(a) begin(a),end(a)

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
int MOD=1000000007;
int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w,bool fl=false)
{
	cout<<w.size()<<en;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<en;
	if (fl) cout<<flush;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

void compress(vi&v)
{
	set<int> s;
	for (auto a: v) s.insert(a);
	vi o(all(s));
	for (auto&a: v) a=lower_bound(all(o),a)-o.begin();
}

void compress(vl&v)
{
	set<ll> s;
	for (auto a: v) s.insert(a);
	vl o(all(s));
	for (auto&a: v) a=lower_bound(all(o),a)-o.begin();
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}

ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int N=3010;
int t,n,s,d;
#define bs bitset<1000>
vector<bs> baz;
bs praz;
bs ar[N];
int id[N];

void ad(bs x)
{
	for (auto a: baz) if (a._Find_first()==x._Find_first()) x^=a;
	if (x!=praz)
	{
		for (int i=0;i<baz.size();++i) if (baz[i]._Find_first()>x._Find_first())
		{
			baz.insert(baz.begin()+i,x);
			return;
		}
		baz.insert(baz.end(),x);
	}
}

int gei(bs x)
{
	int re=0;
	for (int i=0;i<baz.size();++i) if (baz[i]._Find_first()==x._Find_first()) x^=baz[i],re+=1<<i;
	if (x!=praz) return -1;
	return re;
}

void com(vector<pii>&v)
{
	if (v.empty()) return;
	vector<pii> v1={v[0]};
	for (auto a: v) if (a.x!=v1.back().x) v1.pb(a);
	v=v1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>s>>d;
	for (int i=0;i<s;++i)
	{
		int c;
		cin>>c;
		while (c--)
		{
			int a;
			cin>>a;
			--a;
			ar[i][a]=1;
		}
		ad(ar[i]);
	}
	for (int i=0;i<s;++i)
	{
		id[i]=gei(ar[i]);
		//cout<<id[i]<<endl;
		assert(id[i]!=-1);
	}
	vector<pii> p1,p2;
	for (int b=0;b<(1<<(s/2));++b)
	{
		int xo=0;
		for (int i=0;i<s/2;++i) if (b&(1<<i)) xo^=id[i];
		p1.pb({xo,popcnt(b)});
	}
	for (int b=0;b<(1<<((s+1)/2));++b)
	{
		int xo=0;
		for (int i=0;i<(s+1)/2;++i) if (b&(1<<i)) xo^=id[i+s/2];
		p2.pb({xo,popcnt(b)});
	}
	sort(all(p1));
	/*for (auto a: p1) cout<<a.x<<' '<<a.y<<endl;
	cout<<endl;
	for (auto a: p2) cout<<a.x<<' '<<a.y<<endl;
	cout<<endl<<endl;*/
	sort(all(p2));
	com(p1);
	com(p2);
	/*for (auto a: p1) cout<<a.x<<' '<<a.y<<endl;
	cout<<endl;
	for (auto a: p2) cout<<a.x<<' '<<a.y<<endl;
	cout<<endl<<endl;*/
	while (d--)
	{
		bs cu;
		int c;
		cin>>c;
		while (c--)
		{
			int a;
			cin>>a;
			--a;
			cu[a]=1;
		}
		int cui=gei(cu);
		if (cui==-1) cout<<-1<<en;
		else
		{
			int mi=MOD;
			for (auto a: p1)
			{
				auto it=lower_bound(all(p2),pii(cui^a.x,0));
				if (it->x==(cui^a.x)) mi=min(mi,a.y+it->y);
			}
			cout<<mi<<en;
		}
	}
}