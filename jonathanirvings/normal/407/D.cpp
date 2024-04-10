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

#define MAXN 400
 
int r,c,data[MAXN+5][MAXN+5];
int bawah[MAXN+5][MAXN+5];
bool sudah[160005];
short kecil[MAXN+5][MAXN+5][MAXN+5];
 
int main()
{
    scanf("%d %d",&r,&c);
    int risan = 0;
    REP(i,r) REP(j,c) scanf("%d",&data[i][j]);
    REP(yj,c) FORD(yi,yj,0)
    {
        int xj = 0;
        REP(xi,r)
        {
            /*if (data[xi][yi] == data[xi][yj] && yi != yj)
            {
                sudah[data[xi][yi]] = sudah[data[xi][yj]] = 0;
                bawah[xi][yj] = xj;
                ++xj;
                continue;
            }*/
            xj = max(xj,xi);
            while (1)
            {
                if (xj >= r) break;
                if (sudah[data[xj][yi]] || sudah[data[xj][yj]]) break;
                if (data[xj][yi] == data[xj][yj] && yi != yj) break;
                sudah[data[xj][yi]] = sudah[data[xj][yj]] = 1;
                ++xj;
            }
            sudah[data[xi][yi]] = sudah[data[xi][yj]] = 0;
            //bawah[xi][yj] = xj;
            kecil[xi][yi][yj] = xj;
            if (yi < yj) MIN(kecil[xi][yi][yj],kecil[xi][yi+1][yj]);
        }
    }
    REP(yi,c)
    {
        FOR(yj,yi,c)
        {
            int xj = 0;
            REP(xi,r)
            {
                /*if (data[xi][yi] == data[xi][yj] && yi != yj)
                {
                    sudah[data[xi][yi]] = sudah[data[xi][yj]] = 0;
                    bawah[xi][yj] = xj;
                    ++xj;
                    continue;
                }*/
                xj = max(xj,xi);
                while (1)
                {
                    if (xj >= r) break;
                    if (sudah[data[xj][yi]] || sudah[data[xj][yj]]) break;
                    if (data[xj][yi] == data[xj][yj] && yi != yj) break;
                    sudah[data[xj][yi]] = sudah[data[xj][yj]] = 1;
                    ++xj;
                }
                sudah[data[xi][yi]] = sudah[data[xi][yj]] = 0;
                bawah[xi][yj] = xj;
            }
            //REP(xi,r) printf("%d %d %d %d\n",yi,yj,xi,bawah[xi][yj]);
        }
        REP(xi,r)
        {
            //kecil[yi] = bawah[xi][yi];
            //FOR(j,yi+1,c) kecil[j] = min(kecil[j-1],bawah[xi][j]);
            /*if (yi == 0 && xi == 0)
            {
                FOR(j,yi,c) printf("===%d\n",kecil[j]);
                FOR(j,yi,c) printf("===%d\n",bawah[xi][j]);
            }*/
            int angka = INF;
            FOR(yj,yi,c)
            {
                angka = min(angka,(int)kecil[xi][yi][yj]);
                MAX(risan,(angka - xi) * (yj - yi + 1));
                /*if ((angka - xi) * (yj - yi + 1) == 3)
                {
                    printf("====%d %d %d\n",xi,yi,yj);
                }*/
            }
        }
    }
    printf("%d\n",risan);
}