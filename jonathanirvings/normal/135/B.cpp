//Codeforces Beta Round #97
//9 Dec 2011

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

pii data[10];

double jarak(pii a,pii b)
{
	int x = abs(a.fi - b.fi);
	int y = abs(a.se - b.se);
	return sqrt((double)(x * x) + (double)(y * y));
}

bool sama(double a,double b)
{
	return (fabs(a - b) <= EPS);
}

double A,B,C,D,E,F;

int main()
{
	REP(i,8) scanf("%d %d",&data[i].fi,&data[i].se);
	bool bisa = 0;
	REP(i,1 << 8)
	{
		bool ok = 1;
		vector <pii> satu,dua;
		REP(j,8) if(i & (1 << j)) satu.pb(data[j]); else dua.pb(data[j]);
		if (SIZE(satu) != 4) continue;
		//satu
		SORT(satu);
		A = jarak(satu[0],satu[1]);
		B = jarak(satu[0],satu[2]);
		C = jarak(satu[0],satu[3]);
		D = jarak(satu[1],satu[2]);
		E = jarak(satu[1],satu[3]);
		F = jarak(satu[2],satu[3]);
		if (A <= EPS || B <= EPS || C <= EPS || D <= EPS || E <= EPS || F <= EPS)
			continue;
		if (!sama(A,B) || !sama(A,F) || !sama(A,E) || !sama(C,D)) continue;
		//dua
		SORT(dua);
		A = jarak(dua[0],dua[1]);
		B = jarak(dua[0],dua[2]);
		C = jarak(dua[0],dua[3]);
		D = jarak(dua[1],dua[2]);
		E = jarak(dua[1],dua[3]);
		F = jarak(dua[2],dua[3]);
		if (A <= EPS || B <= EPS || C <= EPS || D <= EPS || E <= EPS || F <= EPS)
			continue;
		if (!sama(A,F) || !sama(E,B) || !sama(D,C)) continue;
		puts("YES");
		vi ans1,ans2;
		REP(j,8) if(i & (1 << j)) ans1.pb(j); else ans2.pb(j);
		REP(j,4)
		{
			printf("%d",ans1[j] + 1);
			if (j < 3) printf(" "); else puts("");
		}
		REP(j,4)
		{
			printf("%d",ans2[j] + 1);
			if (j < 3) printf(" "); else puts("");
		}
		return 0;
	}
	puts("NO");
	return 0;
}