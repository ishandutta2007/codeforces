//Codeforces Round #112
//3 June 2012

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

int ada = 0;
char peta[55][55];
int r,c;
bool sudah[55][55];
pii start;
bool cycle = 0;
int risan = 0;
int dirx[4] = {0,0,-1,1};
int diry[4] = {1,-1,0,0};

void dfs(int x,int y)
{
	if (x < 1 || x > r || y < 1 || y > c) return;
	if (sudah[x][y]) return;
	sudah[x][y] = 1;
	if (peta[x][y] == '.') return;
	++risan;
	REP(i,4)
	{
		dfs(x + dirx[i],y + diry[i]);
	}
}

int main()
{
	scanf("%d %d",&r,&c);
	REPN(i,r)
	{
		getchar();
		REPN(j,c) 
		{
			scanf("%c",&peta[i][j]);
			if (peta[i][j] == '#') 
			{
				++ada;
				if (ada == 1) start = mp(i,j);
			}
		}
	}
	if (ada == 1 || ada == 2)
	{
		puts("-1");
		return 0;
	}
	REPN(i,r) REPN(j,c) if(peta[i][j] == '#')
	{
		peta[i][j] = '.';
		RESET(sudah,0);
		risan = 0;
		if (peta[i+1][j] == '#') dfs(i+1,j); else
		if (peta[i-1][j] == '#') dfs(i-1,j); else
		if (peta[i][j+1] == '#') dfs(i,j+1); else
		if (peta[i][j-1] == '#') dfs(i,j-1);
		if (risan < ada - 1)
		{
			puts("1");
			return 0;
		}
		peta[i][j] = '#';
	}
	puts("2");
	return 0;
}