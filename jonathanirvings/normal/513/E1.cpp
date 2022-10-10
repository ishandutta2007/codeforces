//Rockethon 2015
//8 Feb 2014

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
int INF = 1000000000;
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

int dp[405][2][55][2];
int n,k;
int data[405];
int sum[405];
bool sudah[405][2][55][2];

int jahja(int now,int target,int rem,int uwis)
{
    if (rem == 0) return 0;
    if (now == n - 1)
    {
        if (target == 0) return -data[now];
        return data[now];
    }
    int &ret = dp[now][target][rem][uwis];
    if (sudah[now][target][rem][uwis]) return ret;
    sudah[now][target][rem][uwis] = 1;
    ret = -INF;
    if (now + rem < n)
    {
        //if (target == 0) MAX(ret,jahja(now+1,target,rem,uwis));
        MAX(ret,jahja(now+1,target,rem,uwis));
    }
    FORN(i,now,n - rem)
    {
        int res = jahja(i+1,1 - target,rem - 1,1);
        int jum = sum[i] - (now == 0 ? 0 : sum[now-1]);
        if (uwis == 0 || rem == 1)
        { 
            if (target == 0) MAX(ret,-jum + res);
            else MAX(ret,jum + res);    
        } else
        {
            if (target == 0) MAX(ret,-2 * jum + res);
            else MAX(ret,2 * jum + res);
        }
        res = jahja(i+1,target,rem - 1,1);
        if (uwis == 0 && rem == 1)
        {
            if (target == 0) MAX(ret,res);
            else MAX(ret,res); 
        } else
        if (uwis == 0)
        {
            if (target == 0) MAX(ret,jum + res);
            else MAX(ret,-jum + res); 
        } else
        if (rem == 1)
        { 
            if (target == 0) MAX(ret,-jum + res);
            else MAX(ret,jum + res);    
        } else
        {
            if (target == 0) MAX(ret,res);
            else MAX(ret,res);
        }
    }
    //debug("%d %d %d %d\n",now,target,rem,ret);
    return ret;
}

int main()
{
	scanf("%d %d",&n,&k);
    REP(i,n) scanf("%d",&data[i]);
    sum[0] = data[0];
    FOR(i,1,n) sum[i] = sum[i-1] + data[i];
    int risan = max(jahja(0,0,k,0),jahja(0,1,k,0));
    printf("%d\n",risan);
	return 0;
}