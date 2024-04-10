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

int maks = 1;
vi L[105],R[105];
pii data[55];
string c[55];
pii child[105];
int n,m;

int dfs(int now,int maks)
{
    int ret = now;
    if (SIZE(L[now]) == 0 && SIZE(R[now]) == 0)
    {
        if (now == maks) return now;
        child[now].fi = ret + 1;
        ret = dfs(ret+1,maks);
        return ret;
    }
    if (SIZE(L[now]) > 0)
    {
        child[now].fi = ret + 1;
        if (SIZE(R[now]) > 0)
            ret = dfs(ret + 1,L[now][SIZE(L[now])-1]);
        else ret = dfs(ret + 1,max(maks,L[now][SIZE(L[now])-1]));
    }
    //debug("====%d %d %d\n",now,maks,ret);
    if (SIZE(R[now]) > 0)
    {
        if (R[now][0] <= ret)
        {
            puts("IMPOSSIBLE");
            exit(0);
        }
        child[now].se = ret + 1;
        ret = dfs(ret + 1,max(maks,R[now][SIZE(R[now])-1]));
    }
    return ret;
}

void print(int now)
{
    //debug("%d %d %d\n",now,child[now].fi,child[now].se);
    if (child[now].fi != -1) print(child[now].fi);
    printf("%d ",now);
    if (child[now].se != -1) print(child[now].se);
}

int main()
{
	scanf("%d %d",&n,&m);
    REP(i,m)
    {
        scanf("%d %d",&data[i].fi,&data[i].se);
        if (data[i].fi >= data[i].se)
        {
            puts("IMPOSSIBLE");
            return 0;
        }
        c[i] = GetString();
        if (c[i] == "LEFT") L[data[i].fi].pb(data[i].se);
        else R[data[i].fi].pb(data[i].se);
    }
    REPN(i,n) 
    {
        child[i] = mp(-1,-1);
        SORT(L[i]);
        SORT(R[i]);
    }
    int ret = dfs(1,n);
    if (ret != n)
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    print(1);
    puts("");
	return 0;
}