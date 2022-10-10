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
	inline void sz(int x) 
	{
		arr.resize(x+1);
		REP(i,x+1) arr[i] = 0;
	}
	inline void update(int x,int y)
	{
		int m = SIZE(arr);
		while (x < m)
		{
			arr[x] += y;
			x += (x & -x);
		}
	}
	inline int query(int x)
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

BIT jum[1005];
int data[1005][1005];
int r,c,q;
int op,x,y;
int L,R,atas,bawah,kanan,kiri;

void print()
{
	REPN(i,r)
	{
		REPN(j,c) printf("%d ",jum[i].query(j));
		puts("");
	}
}

inline int hitung(int a,int b,int c,int d)
{
	return (jum[c].query(d) - jum[a-1].query(d) - jum[c].query(b-1) + jum[a-1].query(b-1));
}

int main()
{
	scanf("%d %d %d",&r,&c,&q);
	FORN(i,0,r) jum[i].sz(c + 5);
	REPN(i,r) REPN(j,c) 
	{
		scanf("%d",&data[i][j]);
		if (i == 1)
		{
			jum[i].update(j,data[i][j]);
		} else
		{
			int x = jum[i-1].query(j) - jum[i-1].query(j-1) + data[i][j];
			jum[i].update(j,x);
		}
	}
	TC(q)
	{
		scanf("%d %d %d",&op,&x,&y);
		if (op == 1)
		{
			if (data[x][y] == 1)
			{
				FORN(i,x,r) jum[i].update(y,-1);
			} else
			{
				FORN(i,x,r) jum[i].update(y,1);
			}
			data[x][y] = 1 - data[x][y];
		} else
		{
			int risan = 0;
			//kiri
			FORN(i,y,c)
			{
				L = 1;
				R = x;
				atas = 0;
				while (L <= R)
				{
					int M = (L + R) >> 1;
					if (hitung(M,y,x,i) == (i - y + 1) * (x - M + 1))
					{
						atas = M;
						R = M - 1;
					} else L = M + 1;
				}
				if (atas == 0) continue;
				L = x;
				R = r;
				bawah = 0;
				while (L <= R)
				{
					int M = (L + R) >> 1;
					if (hitung(x,y,M,i) == (i - y + 1) * (M - x + 1))
					{
						bawah = M;
						L = M + 1;
					} else R = M - 1;
				}
				if (bawah == 0) continue;
				MAX(risan,(bawah - atas + 1) * (i - y + 1));
			}

			//kanan
			FORN(i,1,y)
			{
				L = 1;
				R = x;
				atas = 0;
				while (L <= R)
				{
					int M = (L + R) >> 1;
					if (hitung(M,i,x,y) == (y - i + 1) * (x - M + 1))
					{
						atas = M;
						R = M - 1;
					} else L = M + 1;
				}
				if (atas == 0) continue;
				L = x;
				R = r;
				bawah = 0;
				while (L <= R)
				{
					int M = (L + R) >> 1;
					if (hitung(x,i,M,y) == (y - i + 1) * (M - x + 1))
					{
						bawah = M;
						L = M + 1;
					} else R = M - 1;
				}
				if (bawah == 0) continue;
				MAX(risan,(bawah - atas + 1) * (y - i + 1));
			}

			//atas
			FORN(i,x,r)
			{
				L = 1;
				R = y;
				//printf("%d %d %d\n",i,L,R);
				kiri = 0;
				while (L <= R)
				{
					int M = (L + R) >> 1;
					if (hitung(x,M,i,y) == (i - x + 1) * (y - M + 1))
					{
						kiri = M;
						R = M - 1;
					} else L = M + 1;
				}
				//printf("%d %d %d\n",i,L,R);
				if (kiri == 0) continue;
				//printf("%d %d %d\n",i,kiri,kanan);
				L = y;
				R = c;
				kanan = 0;
				while (L <= R)
				{
					int M = (L + R) >> 1;
					if (hitung(x,y,i,M) == (i - x + 1) * (M - y + 1))
					{
						kanan = M;
						L = M + 1;
					} else R = M - 1;
				}
				if (kanan == 0) continue;
				//printf("%d %d %d\n"/,i,kiri,kanan);
				MAX(risan,(kanan - kiri + 1) * (i - x + 1));
			}

			//bawah
			FORN(i,1,x)
			{
				L = 1;
				R = y;
				kiri = 0;
				while (L <= R)
				{
					int M = (L + R) >> 1;
					if (hitung(i,M,x,y) == (x - i + 1) * (y - M + 1))
					{
						kiri = M;
						R = M - 1;
					} else L = M + 1;
				}
				if (kiri == 0) continue;
				L = y;
				R = c;
				kanan = 0;
				while (L <= R)
				{
					int M = (L + R) >> 1;
					if (hitung(i,y,x,M) == (x - i + 1) * (M - y + 1))
					{
						kanan = M;
						L = M + 1;
					} else R = M - 1;
				}
				if (kanan == 0) continue;
				MAX(risan,(kanan - kiri + 1) * (x - i + 1));
			}


			printf("%d\n",risan);
		}
	}
	return 0;
}