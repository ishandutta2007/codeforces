//Codeforces Beta Round #96
//3 Dec 2011

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
int n,k;
int dp[210][105][105][2];

int solve(int pos,int ix,int chance,int dir)
{
	//printf("%d %d %d %d\n",pos,ix,chance,dir);
	if (dp[pos][ix][chance][dir] != -1) return dp[pos][ix][chance][dir];
	if (ix == n)
	{
		if (chance % 2 == 0)
		{
			if (s[n] == 'T') return abs(pos - 102);
			int next = pos + (dir == 0 ? -1 : 1);
			return abs(next - 102);
		}
		if (chance % 2 == 1)
		{
			int next = pos + (dir == 0 ? -1 : 1);
			if (s[n] == 'T') return abs(next - 102);
			return abs(pos - 102);
		}
		return -INF;
	}
	int res = -INF;
	//gak ganti
	if (s[ix] == 'T')
	{
		res = max(res,solve(pos,ix+1,chance,1 - dir));
	} else
	{
		int next = pos + (dir == 0 ? -1 : 1);
		res = max(res,solve(next,ix + 1,chance,dir));
	}
	//ganti
	if (chance > 0)
	{
		if (s[ix] == 'T')
		{
			int next = pos + (dir == 0 ? -1 : 1);
			res = max(res,solve(next,ix + 1,chance - 1,dir));
		} else
		{
			res = max(res,solve(pos,ix+1,chance-1,1 - dir));
		}
	}
	dp[pos][ix][chance][dir] = res;
	return res;
}

int main()
{
	RESET(dp,-1);
    s = GetString();
    s = '0' + s;
    n = SIZE(s) - 1;
    scanf("%d",&k);
    int ans = solve(102,1,k,1);
    printf("%d\n",ans);
	return 0;
}