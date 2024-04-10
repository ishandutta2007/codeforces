//VK Cup 2012 Qualification Round 2
//9 mar 2012

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

string s;
bool palin[2005][2005];
int ada[2005],n;
LL jum[2005];
LL ans = 0;

int main()
{
	s = GetString();
	n = SIZE(s);
	RESET(palin,0);
	REP(i,n) palin[i][i] = 1;
	REP(i,n-1) if(s[i] == s[i+1]) palin[i][i+1] = 1;
	FORN(dif,3,n) FORN(i,0,n-dif+1) 
		palin[i][i+dif-1] = (palin[i+1][i+dif-2] && (s[i] == s[i+dif-1]));
	REP(i,n) FOR(j,i,n) if(palin[i][j]) ++ada[i];
	jum[0] = ada[0];
	FOR(i,1,n) jum[i] = jum[i-1] + (LL)ada[i];
	FOR(i,0,n-1) FOR(j,i,n-1) if(palin[i][j]) ans += (LL)(jum[n-1] - jum[j]);
	cout << ans << endl;
	return 0;
}