//Codeforces Beta Round #92
//3 Nov 2011

//start of jonathanirvings' template v1.0.3

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
#define SQR(x) (x * x)
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
    sprintf(x,"%d",a);
    string s = x;
    return s;
}

inline int StringToInt(string a)
{
    char x[100]; int res;
    strcpy(x,a.c_str());
    sscanf(x,"%d",&res);
    return res;
}

inline bool angka(char a) { return (a >= '0' && a <= '9'); }
inline bool kecil(char a) { return (a >= 'a' && a <= 'z'); }
inline bool besar(char a) { return (a >= 'A' && a <= 'Z'); }

inline string uppercase(string s)
{
    int n = SIZE(s);
    REP(i,n) if (kecil(s[i])) s[i] = s[i] - 'a' + 'A';
    return s;
}

inline string lowercase(string s)
{
    int n = SIZE(s);
    REP(i,n) if (besar(s[i])) s[i] = s[i] - 'A' + 'a';
    return s;
}

//end of jonathanirvings' template v1.0.3

#define MAXN 1000

bool pr[MAXN+5];
int prima[MAXN+5];

void GeneratePrime(int a)
{
    memset(pr,1,sizeof(pr));
    pr[0] = pr[1] = 0;
    int ix = 0;
    FORN(i,2,a)
    {
        if (pr[i])
        {
            ix++;
            prima[ix] = i;
            int b = i * 2;
            while (b <= a)
            {
                pr[b] = 0;
                b = b + i;
            }
        }
    }
}

string s;
pair <int,char> data[30];
char ans[1005];
vii mboh;

bool g(vi a,vi b)
{
    int A = SIZE(a);
    int B = SIZE(b);
    if (A > B) return true;
    if (B < A) return false;
    return (a[0] >= b[0]);
}

int main()
{
    GeneratePrime(MAXN);
    int n = 0;
    cin >> s;
    int len = SIZE(s);
    REP(i,len)
    {
            char now = s[i];
            bool ada = 0;
            REPN(j,n) if(data[j].se == now)
            {
                ada = 1;
            data[j].fi++;
                break;
            }
            if (!ada)
            {
                n++;
                data[n].fi = 1;
                data[n].se = now;
            }
    }
    SORTA(data,n);
    REVERSEA(data,n);
    //REPN(i,n) printf("%d %c\n",data[i].fi,data[i].se);
    REPN(i,168)
    {
        if (prima[i] > len) break;
        vi tmp;
        tmp.clear();
        int a = prima[i];
        bool murni = 1;
        int pindah = -1;
        while (a <= len)
        {
            REP(j,SIZE(mboh))
            {
                REP(k,SIZE(mboh[j]))
                {
                    if (a == mboh[j][k])
                    {
                        murni = 0;
                        REP(l,SIZE(tmp)) mboh[j].pb(tmp[l]);
                        pindah = j;
                        break;
                    }
                    if (!murni) break;
                }
                if (!murni) break;
            }
            if (murni) tmp.pb(a);
            else 
            {
                bool ada = 0;
                REP(k,SIZE(mboh[pindah]))
                {
                    if (mboh[pindah][k] == a)
                    {
                        ada = 1;
                        break;
                    }
                }
                if (!ada) mboh[pindah].pb(a);
            }
            a = a + prima[i];
        }
        if (murni) mboh.pb(tmp);
    }
    vi tmp;
    tmp.pb(1);
    mboh.pb(tmp);
    //REP(i,SIZE(mboh)) printf("%d %d\n",i,SIZE(mboh[i]));
    /*REP(i,SIZE(mboh))
    {
        REP(j,SIZE(mboh[i])) printf("%d ",mboh[i][j]);
        puts("");
    }*/
    int A = 1;
    int B = 0;
    while (A <= n && B < SIZE(mboh))
    {
        if (data[A].fi > SIZE(mboh[B]))
        {
            REP(i,SIZE(mboh[B])) ans[mboh[B][i]] = data[A].se;
            data[A].fi -= SIZE(mboh[B]);
            B++;
        } else if (data[A].fi == SIZE(mboh[B]))
        {
            REP(i,SIZE(mboh[B])) 
            {
                //printf("%d\n",A);
                ans[mboh[B][i]] = data[A].se;
            }
            A++;
            B++;
        } else
        {
            //REP(i,data[A].fi) ans[mboh[B][i]] = data[A].se;
            puts("NO");
            return 0;
        }
    }
    //printf("%d\n",len);
    REPN(i,len) if (!kecil(ans[i]))
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    REPN(i,len) printf("%c",ans[i]);
    puts("");
    return 0;
}