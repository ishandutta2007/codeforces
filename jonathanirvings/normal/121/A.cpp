//Codeforces Beta Round #91
//27 Oct 2011

//start of jonathanirvings' template v1.0.0

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
typedef pair<int,int> pii;
typedef double db;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);

#define DEBUG printf("====TESTING====\n")
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);(a)++)
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);(a)++)
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);(a)++)
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define SORTA(arr,sz) sort(arr+1,arr+1+sz)
#define TC(t) while(t--)

string IntToString(int a)
{
    char x[100];
    sprintf(x,"%d",a);
    string s = x;
    return s;
}

LL StringToInt(string a)
{
    char x[100];
    strcpy(x,a.c_str());
    LL res;
    //sscanf(x,"%lld",&res);
    sscanf(x,"%I64d",&res);
    return res;
}

//end of jonathanirvings' template v1.0.0

int l,r;
LL lucky[10000000];

int main()
{
    scanf("%d %d",&l,&r);
    string a = "4";
    int ix = 0;
    lucky[0] = 0;
    while (1)
    {
        ix++;
        lucky[ix] = StringToInt(a);
        int sz = a.length();
        int cek = sz-1;
        
        while (cek >= 0 && a[cek] == '7') cek--;
        string stmp = "";
        FOR(i,0,cek) stmp = stmp + a[i];
        a = stmp;
        if (cek == -1)
        {
            FORN(i,0,sz) a = a + '4';
        } else
        {
            //FOR(i,0,cek) a = a + '4';
            a = a + '7';
            FOR(i,cek,sz-1) a = a + '4';
        }        
        if (a == "4444444474") 
        {
            //printf("%d\n",ix);
            break;
        }
    }
    ix--;
    //FORN(i,1,1023) printf("%lld\n",lucky[i]);
    //printf("%d\n",lucky[1023]);
    int mulai = lower_bound(lucky,lucky+1+ix,(LL)l) - lucky;
    int selesai = upper_bound(lucky,lucky+1+ix,(LL)r) - lucky;
    selesai--;
    //printf("%d %d\n",mulai,selesai);
    if (selesai < mulai)
    {
        printf("%I64d\n",(LL)(r - l + 1) * (LL)lucky[mulai]);
        //printf("%lld\n",(LL)(r - l + 1) * (LL)lucky[mulai]);
        return 0;
    }
    LL ans = (LL)(lucky[mulai] - l + 1) * (LL)lucky[mulai];
        //printf("%lld\n",ans);
    ans = ans + (LL)(r - lucky[selesai]) * (LL)lucky[selesai + 1];
        //printf("%lld\n",ans);
    FOR(i,mulai,selesai) 
        ans = ans + (LL)(lucky[i+1] - lucky[i]) * (LL)(lucky[i+1]);
    printf("%I64d\n",ans);
    //printf("%lld\n",ans);
	return 0;
}