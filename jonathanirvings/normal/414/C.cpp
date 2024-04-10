//start of jonathanirvings' template v2.0.0 (BETA)

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>
jonathan ganteng banget;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
	#define DEBUG fprintf(stderr,"====TESTING====\n")
	#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define DEBUG 
	#define VALUE(x)
	#define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);++(a))
#define FORLSQ(a,b,c) for (int (a)=(b);(LL)(a)*(LL)(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
#define READ(n,data) {scanf("%d",&n); REPN(i,n) scanf("%d",&data[i]);}

inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

inline string uppercase(string s){
	int n = SIZE(s); 
	REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
	return s;
}

inline string lowercase(string s){
	int n = SIZE(s); 
	REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
	return s;
}

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v2.0.0 (BETA)

struct BIT
{
	vi arr;
	void sz(int x) 
	{
		arr.resize(x+1);
		REP(i,x+1) arr[i] = 0;
	}
	void update(int x,int y)
	{
		int m = SIZE(arr);
		while (x < m)
		{
			arr[x] += y;
			x += (x & -x);
		}
	}
	int query(int x)
	{
		int ret = 0;
		while (x > 0)
		{
			ret += arr[x];
			x -= (x & -x);
		}
		return ret;
	}
};

int m,n,q,data[1200005];
pair<LL,LL> ada[25];
LL tot[25];
set<int> S;
vi angka;
map<int,int> ix;

void compress(void)
{
	REP(i,n) angka.pb(data[i]);
	SORT(angka);
	angka.erase(unique(ALL(angka)),angka.end());
	REP(i,SIZE(angka)) ix[angka[i]] = i+1;
	REP(i,n) data[i] = ix[data[i]];
}

BIT bit;

int main()
{
	scanf("%d",&m); n = 1 << m;
	REP(i,n) scanf("%d",&data[i]);
	compress();
	//REP(i,n) VALUE(data[i]);
	LL risan = 0;
	REP(i,m)
	{
		bit.sz(n+5);
		ada[i] = mp(0,0);
		REP(j,n)
		{
			int x = j / (1 << i);
			if (x % 2 == 0)
			{
				if (j % (1 << i) == 0)
				{
					if (j != 0)
					{
						FOR(k,j - 2 * (1 << i),j - (1 << i))
							bit.update(data[k],-1);
					}
				}
				bit.update(data[j],1);
			} else
			{
				int y = bit.query(data[j]);
				int z = bit.query(data[j]-1);
				ada[i].fi += ((1 << i) - y);
				ada[i].se += y - z;
			}
		}
		risan += ada[i].fi;
		tot[i] = (LL)(1LL << i) * n / 2;
		//printf("%lld %lld %lld\n",ada[i].fi,ada[i].se,tot[i]);
	}
	scanf("%d",&q);
	TC(q)
	{
		int x;
		scanf("%d",&x);
		REP(i,x)
		{
			LL sisa = tot[i] - ada[i].fi - ada[i].se;
			risan = risan - ada[i].fi + sisa;
			ada[i].fi = sisa;
		}
		printf("%I64d\n",risan);
	}
	return 0;
}