//Codeforces Round #117
//24 Apr 2012

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
int INF = 102;
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

int dp[105][105][3005];
int MOD = 1000000007;
int n,l,ans;
pii data[105];

int jahja(int x,int last,int rem)
{
    //printf("%d %d %d\n",x,last,rem);
    if (rem < 0) return 0;
    if (rem == 0) return 1;
    int &ret = dp[x][last][rem];
    if (ret != -1) return ret;
    ret = 0;
    FORN(i,1,n) if(i != x)
    {
        if (last == INF) 
        {
            int satu = jahja(i,data[i].fi,rem - data[i].se);
            int dua = jahja(i,data[i].se,rem - data[i].fi);
            int tot = (satu + dua) % MOD;
            if (data[i].fi == data[i].se) ret = (ret + satu) % MOD;
            else ret = (ret + tot) % MOD;
            //ret = (ret + max(satu,dua)) % MOD;
            //ret = (ret + tot) % MOD;
        } else
        {
            if (data[i].fi == data[i].se)
            {
                if (data[i].fi == last)
                    ret = (ret + jahja(i,last,rem - last)) % MOD;
            } else
            {
                if (data[i].fi == last) 
                    ret = (ret + jahja(i,data[i].se,rem - data[i].fi)) % MOD; 
                if (data[i].se == last)
                    ret = (ret + jahja(i,data[i].fi,rem - data[i].se)) % MOD;
            }
        }
    }
    return ret;
}

int main()
{
    scanf("%d %d",&n,&l);
    REPN(i,n) scanf("%d %d",&data[i].fi,&data[i].se);
    RESET(dp,-1);
    //VALUE(jahja(5,5,2));
    //return 0;
    int risan = jahja(0,INF,l);
        printf("%d\n",risan);
    return 0;
}