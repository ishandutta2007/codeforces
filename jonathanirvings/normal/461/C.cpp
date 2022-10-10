//Codeforces Round #263
//26 Aug 2014

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

int n,m,now,kanan,sz;
int type,a,b,c;
BIT bit;

int jum(int a,int b)
{
	if (a > b) swap(a,b);
	return (bit.query(b) - bit.query(a-1));
}

int isi(int a)
{
	return bit.query(a) - bit.query(a-1);
}

int main()
{
	scanf("%d %d",&n,&m);
	bit.sz(n+5);
	kanan = 1;
	sz = n;
	now = 1;
	REPN(i,n) bit.update(i,1);
	TC(m)
	{
		scanf("%d",&type);
		if (type == 1)
		{
			scanf("%d",&a);
			if (a <= sz / 2)
			{
				if (kanan)
				{
					REP(i,a)
					{
						bit.update(now + i + a,isi(now + a - i - 1));
					}
					now += a;
					sz -= a;
				} else
				{
					REP(i,a)
					{
						bit.update(now - i - a,isi(now - a + i + 1));
					}
					now -= a;
					sz -= a;
				}
			} else
			{
				a = sz - a;
				if (kanan)
				{
					b = now + sz - 1;
					REP(i,a)
					{
						bit.update(b - 2 * a + i + 1,isi(b-i));
					}
					kanan = false;
					sz -= a;
					now = b - a;
				} else
				{
					b = now - sz + 1;
					REP(i,a)
					{
						//bit.update(b + 2 * a - i - 1,isi(b + i));
						bit.update(b + 2 * a - i - 1,isi(b+i));
					}
					kanan = true;
					sz -= a;
					now = b + a;
				}
			}
			//printf("%d %d %d\n",now,kanan,sz);
			//FORN(i,1,n) printf("%d ",isi(i));
			//puts("");
		} else
		{
			scanf("%d %d",&a,&b);
			--b;
			if (kanan)
			{
				printf("%d\n",jum(now + a,now + b));
			} else
			{
				printf("%d\n",jum(now - a,now - b));
			}
		}
	}
	return 0;
}