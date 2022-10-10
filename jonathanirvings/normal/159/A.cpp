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

int n,d,m,x;
pair<pii,int> data[1005];
map<string,int> nomor;
string nama[2005];
string s1,s2;
bool sudah[2005][2005];
vector<pii> ans;

int main()
{
	scanf("%d %d",&n,&d);
	m = 0;
	REPN(i,n)
	{
		getchar();
		s1 = GetString();
		s2 = GetString();
		if (nomor.count(s1) == 0)
		{
			nomor[s1] = ++m;
			nama[m] = s1;
		}
		if (nomor.count(s2) == 0)
		{
			nomor[s2] = ++m;
			nama[m] = s2;
		}
		scanf("%d",&x);
		data[i] = mp(mp(nomor[s1],nomor[s2]),x);
	}    
	//REPN(i,n) printf("%d %d %d\n",data[i].fi.fi,data[i].fi.se,data[i].se);
	REPN(i,n) FORN(j,i+1,n) 
	{
		if (data[i].fi.fi == data[j].fi.se && data[i].fi.se == data[j].fi.fi)
		{
			if (abs(data[i].se - data[j].se) <= d && data[i].se != data[j].se)
			{
				if (!sudah[data[i].fi.fi][data[i].fi.se])
				{
					sudah[data[i].fi.fi][data[i].fi.se] = 1;
					sudah[data[i].fi.se][data[i].fi.fi] = 1;
					ans.pb(mp(data[i].fi.fi,data[i].fi.se));
				}
			}
		}
	}
	int sz = SIZE(ans);
	printf("%d\n",sz);
	REP(i,sz) printf("%s %s\n",nama[ans[i].fi].c_str(),nama[ans[i].se].c_str());
	return 0;
}