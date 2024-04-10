//Codeforces Beta Round #95
//25 Nov 2011

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

int n,m,t;
LL ans = 0;

LL kom(int a,int b)
{
	LL res = 1;
	if (b > a / 2) b = a - b;
	vl data1,data2;
	FORD(i,a,a-b+1) data1.pb((LL)i);
	FORN(i,1,b) data2.pb((LL)i);
	REP(i,SIZE(data1)) REP(j,SIZE(data2))
	{
		LL tmp = __gcd(data1[i],data2[j]);
		data1[i] /= tmp;
		data2[j] /= tmp;
	}
	REP(i,SIZE(data1)) res = res * data1[i];
	REP(i,SIZE(data2)) res /= data2[i];
	return res;
}

int main()
{
	scanf("%d %d %d",&n,&m,&t);
	//printf("%lld\n",fak[10]);
	FORN(i,4,n)
	{
		int p = t - i;
		if (p < 1) continue;
		if (p > m) continue;
		ans += kom(n,i) * kom(m,p);
		//printf("%lld %lld %lld\n",ans,kom(n,i),kom(m,p));
		//printf("%lld\n",kom(n,i));
	}   
	printf("%I64d\n",ans);
	return 0;
}