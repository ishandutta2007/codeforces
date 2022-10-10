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

int m,n;
pair<vii,double> risan;
pii coba[10];
int jarak = 0;

int hitung(void)
{
	double ret = 0;
	REP(i,3)
	{
		ret += sqrt(SQR(coba[i].fi-coba[i+1].fi)+SQR(coba[i].se-coba[i+1].se));
	}
	if (ret > risan.se)
	{
		risan.fi.clear();
		REP(i,4) risan.fi.pb(coba[i]);
		risan.se = ret;
	}
	return 0;
}

void print(void)
{
	REP(i,4) printf("%d %d\n",(int)risan.fi[i].fi,(int)risan.fi[i].se);
}

/*void brute(void)
{
	FORN(ix,0,m) FORN(iy,0,n) FORN(jx,0,m) FORN(jy,0,n)
	{
		if (mp(ix,iy) == mp(jx,jy)) continue;
		FORN(kx,0,m) FORN(ky,0,n) FORN(lx,0,m) FORN(ly,0,n)
		{
			if (mp(ix,iy) == mp(kx,ky)) continue;
			if (mp(jx,jy) == mp(kx,ky)) continue;
			if (mp(ix,iy) == mp(lx,ly)) continue;
			if (mp(jx,jy) == mp(lx,ly)) continue;
			if (mp(kx,ky) == mp(lx,ly)) continue;
			int DST = hypot(SQR(ix-jx),SQR(iy-jy));
			DST += hypot(SQR(kx-jx),SQR(ky-jy));
			DST += hypot(SQR(kx-lx),SQR(ky-ly));
			if (DST > jarak)
			{
				printf("%d %d\n",ix,iy);
				printf("%d %d\n",jx,jy);
				printf("%d %d\n",kx,ky);
				printf("%d %d\n",lx,ly);
				puts("");
				MAX(jarak,DST);
			}
		}
	}
	printf("%.6lf\n",jarak);
}*/

int main()
{
	risan.se = -INF;
	scanf("%d %d",&m,&n);
	//brute();
	jarak = 0;
	if (m == 0)
	{
		printf("%d %d\n",0,1);
		printf("%d %d\n",0,n);
		printf("%d %d\n",0,0);
		printf("%d %d\n",0,n-1);
		/*jarak += hypot(SQR(0-0),SQR(n-1));
		jarak += hypot(SQR(0-0),SQR(n-0));
		jarak += hypot(SQR(0-0),SQR(n-1));
		printf("%.6lf\n",jarak);*/
		return 0;
	}
	if (n == 0)
	{
		printf("%d %d\n",1,0);
		printf("%d %d\n",m,0);
		printf("%d %d\n",0,0);
		printf("%d %d\n",m-1,0);
		/*jarak += hypot(SQR(0-0),SQR(m-1));
		jarak += hypot(SQR(0-0),SQR(m-0));
		jarak += hypot(SQR(0-0),SQR(m-1));
		printf("%.6lf\n",jarak);*/
		return 0;
	}
	FORN(i,1,n) FORN(j,0,n-1)
	{
		coba[0] = mp(0,0);
		coba[1] = mp(m,n);
		coba[2] = mp(0,i);
		coba[3] = mp(m,j);
		hitung();

		coba[0] = mp(0,i);
		coba[1] = mp(m,n);
		coba[2] = mp(0,0);
		coba[3] = mp(m,j);
		hitung();

		coba[0] = mp(0,0);
		coba[1] = mp(m,j);
		coba[2] = mp(0,i);
		coba[3] = mp(m,n);
		hitung();

		coba[0] = mp(0,i);
		coba[1] = mp(m,j);
		coba[2] = mp(0,0);
		coba[3] = mp(m,n);
		hitung();
	}
	FORN(i,1,m) FORN(j,0,m-1)
	{
		coba[0] = mp(0,0);
		coba[1] = mp(m,n);
		coba[2] = mp(i,0);
		coba[3] = mp(j,n);
		hitung();

		coba[0] = mp(i,0);
		coba[1] = mp(m,n);
		coba[2] = mp(0,0);
		coba[3] = mp(j,n);
		hitung();

		coba[0] = mp(0,0);
		coba[1] = mp(j,n);
		coba[2] = mp(i,0);
		coba[3] = mp(m,n);
		hitung();

		coba[0] = mp(i,0);
		coba[1] = mp(j,n);
		coba[2] = mp(0,0);
		coba[3] = mp(m,n);
		hitung();
	}
	print();
	//printf("%.6lf\n",risan.se);
	return 0;
}