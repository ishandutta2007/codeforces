//VK Cup 2012 Round 1
//11 Mar 2012

//start of jonathanirvings' template v1.1.0 (BETA)

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
jonathan ganteng banget;

typedef long long LL;
typedef vector <int> vi;
typedef vector <vi> vii;
typedef vector <LL> vl;
typedef vector <vl> vll;
typedef vector <string> vstr;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);

#define DEBUG printf("====TESTING====\n")
#define VALUE(x) cout << "The value of " << #x << " is " << x << endl;
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);(a)++)
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);(a)++)
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);(a)++)
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
#define MAX(a,b) a = max(a,b);
#define MIN(a,b) a = min(a,b);
#define SQR(x) ((x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr+1,arr+1+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE(v) next_permutation(ALL(v))
#define PERMUTEA(arr,sz) next_permutation(ALLA(arr,sz))
#define TC(t) while(t--)

inline string IntToString(int a)
{
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a)
{
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void)
{
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

inline bool angka(char a) { return (a >= '0' && a <= '9'); }
inline bool kecil(char a) { return (a >= 'a' && a <= 'z'); }
inline bool besar(char a) { return (a >= 'A' && a <= 'Z'); }

inline string uppercase(string s){
	int n = SIZE(s); REP(i,n) if (kecil(s[i])) s[i] = s[i] - 'a' + 'A';
	return s;
}

inline string lowercase(string s){
	int n = SIZE(s); REP(i,n) if (besar(s[i])) s[i] = s[i] - 'A' + 'a';
	return s;
}

//end of jonathanirvings' template v1.1.0 (BETA)

int n,k,a,b,m;
vector<pii> stool,pencil,gabung;
vi ans[1005];
int price[1005];
double harga = 0.0;
bool sudah[1005];
int masuk = 0;
bool ada[1005];

bool f(int a,int b)
{
	return (price[a] < price[b]);
}

int main()
{
 	scanf("%d %d",&n,&k);
 	REPN(i,n)
 	{
 		scanf("%d %d",&a,&b);
 		price[i] = a;
 		if (b == 1) stool.pb(mp(a,i));
 		else pencil.pb(mp(a,i));
 		gabung.pb(mp(a,i));
 	}   
 	SORT(stool);
 	SORT(pencil);
 	SORT(gabung);
 	REVERSE(stool);
 	REVERSE(gabung);
 	REVERSE(pencil);
 	n = SIZE(stool);
 	m = SIZE(pencil);
	if (n >= k)
	{
		REP(i,k) 
		{
			ans[i].pb(stool[i].se);
			sudah[stool[i].se] = 1;
			ada[i] = 1;
		}
		REP(i,n+m) 
		{
			if (!sudah[gabung[i].se])
			{
				ans[k-1].pb(gabung[i].se);
				sudah[gabung[i].se] = 1;
			}
		}
		REP(i,k) sort(ALL(ans[i]),f);
		REP(i,k)
		{
			//VALUE(harga);
			int sz = SIZE(ans[i]);
			if (ada[i]) harga += (double)price[ans[i][0]] / 2.0;
			else harga += (double)price[ans[i][0]];
			FOR(j,1,sz) harga += (double)price[ans[i][j]];
		}
		printf("%.1lf\n",harga);
		REP(i,k)
		{
			int sz = SIZE(ans[i]);
			printf("%d",sz);
			REP(j,sz) printf(" %d",ans[i][j]);
			puts("");
		}
	} else
	{
		REP(i,n) 
		{
			ans[i].pb(stool[i].se);
			sudah[stool[i].se] = 1;
			ada[i] = 1;
		}
		masuk = n;
		REP(i,n+m) 
		{
			if (masuk == k-1) break;
			if (!sudah[gabung[i].se])
			{
				ans[masuk].pb(gabung[i].se);
				sudah[gabung[i].se] = 1;
				++masuk;
				if (masuk == k-1) break;
			}
		}
		REP(i,n+m)
		{
			if (!sudah[gabung[i].se])
			{
				ans[k-1].pb(gabung[i].se);
				sudah[gabung[i].se] = 1;
			}
		}
		REP(i,k) sort(ALL(ans[i]),f);
		REP(i,k)
		{
			//VALUE(harga);
			int sz = SIZE(ans[i]);
			//VALUE(sz);
			if (ada[i]) harga += (double)price[ans[i][0]] / 2.0;
			else harga += (double)price[ans[i][0]];
			FOR(j,1,sz) harga += (double)price[ans[i][j]];
		}
		printf("%.1lf\n",harga);
		REP(i,k)
		{
			int sz = SIZE(ans[i]);
			printf("%d",sz);
			REP(j,sz) printf(" %d",ans[i][j]);
			puts("");
		}
	}
	return 0;
}