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

double prob[10005];
int n;
pii data[6];

int main()
{
	scanf("%d",&n);
    REP(i,n) scanf("%d %d",&data[i].fi,&data[i].se);
    double risan = 0;
    REP(i,n)
    {
        swap(data[i],data[n-1]);
        int m = n - 1;
        FORN(j,1,10000)
        {
            prob[j] = 0;
            REP(bit,1 << m) if (bit > 0)
            {
                double res = 1;
                REP(k,m) if(bit & (1 << k))
                {
                    if (data[k].fi <= j && j <= data[k].se)
                    {
                        res *= 1.0 / (double)(data[k].se - data[k].fi + 1);
                    } else goto hell;
                } else
                {
                    if (data[k].fi >= j) goto hell;
                    int batas = min(data[k].se,j-1);
                    res *= (double)(batas - data[k].fi + 1) / (double)(data[k].se - data[k].fi + 1);
                    //if (i == 1 && j == 7) VALUE(res);
                }
                prob[j] += res;
                //VALUE(prob[j]);
                hell:;
            }
        }
        //REP(j,m) printf("%d %d\n",data[j].fi,data[j].se);
        //FORN(j,1,10) printf("%.2lf ",prob[j]);
        //puts("");
        FORN(j,1,10000) prob[j] = prob[j] * j + prob[j-1];
        //FORN(j,1,10) printf("%.2lf ",prob[j]);
        //puts("");
        swap(data[i],data[n-1]);
        //printf("%d %d\n",data[i].fi,data[i].se);
        FORN(j,data[i].fi,data[i].se)
        {
            risan += 1.0 / (double)(data[i].se - data[i].fi + 1) * prob[j-1];
        }
    }
    FORN(j,1,10000)
    {
        REP(bit,1 << n) if(__builtin_popcount(bit) > 1)
        {
            double res = j;
            REP(i,n) if(bit & (1 << i))
            {
                if (data[i].fi <= j && j <= data[i].se)
                {
                    res *= 1.0 / (double)(data[i].se - data[i].fi + 1);
                } else goto hell2;
            } else 
            {
                if (data[i].fi >= j) goto hell2;
                int batas = min(data[i].se,j-1);
                res *= (double)(batas - data[i].fi + 1) / (double)(data[i].se - data[i].fi + 1);
            }
            risan += res;
            hell2:;
        }
    }
    printf("%.10lf\n",risan);
	return 0;
}