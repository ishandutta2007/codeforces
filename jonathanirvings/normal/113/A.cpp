//start of jonathanirvings' template

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

#define DEBUG printf("====TESTING====\n")
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);(a)++)
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);(a)++)
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);(a)++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define SIZE(v) (int)v.size()
#define SORT(v) sort(v.begin(),v.end())
#define SORTA(arr,sz) sort(arr+1,arr+1+sz)
#define RESET(a,b) memset(a,b,sizeof(a))

//end of jonathanirvings' template

//Codeforces Beta Round #86 - 8 Sep 2011

string s;

bool adjm(string a)
{
    if (a.length() < 4) return 0;
    string coba = "";
    FOR(i,SIZE(a)-4,SIZE(a)) coba = coba + a[i];
    return (coba == "lios");
}

bool adjf(string a)
{
    if (a.length() < 5) return 0;
    string coba = "";
    FOR(i,SIZE(a)-5,SIZE(a)) coba = coba + a[i];
    return (coba == "liala");
}

bool nounm(string a)
{
    if (a.length() < 3) return 0;
    string coba = "";
    FOR(i,SIZE(a)-3,SIZE(a)) coba = coba + a[i];
    return (coba == "etr");
}

bool nounf(string a)
{
    if (a.length() < 4) return 0;
    string coba = "";
    FOR(i,SIZE(a)-4,SIZE(a)) coba = coba + a[i];
    return (coba == "etra");
}

bool verbm(string a)
{
    if (a.length() < 6) return 0;
    string coba = "";
    FOR(i,SIZE(a)-6,SIZE(a)) coba = coba + a[i];
    return (coba == "initis");
}

bool verbf(string a)
{
    if (a.length() < 6) return 0;
    string coba = "";
    FOR(i,SIZE(a)-6,SIZE(a)) coba = coba + a[i];
    return (coba == "inites");
}

int main()
{
    vector <string> data;
    string s;
    int kata = 0;
    bool bisa = 1;
    char gender = '?';
    bool bolehadj = 1;
    bool bolehnoun = 1;
    bool bolehverb = 0;
    while (cin >> s) 
    {
        data.pb(s);
    }
    if (SIZE(data) == 1)
    {
        s = data[0];
        if (!adjm(s) && !adjf(s) && !nounm(s) && !nounf(s) && !verbf(s) && !verbm(s))
        {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        return 0;
    }
    FOR(i,0,SIZE(data))
    {
        s = data[i];
        kata++;
        //printf("%s\n",s.c_str());
        if (adjm(s))
        {
            if (bolehadj && gender != 'f')
            {
                gender = 'm';
            } else
            {
                printf("NO\n");
                return 0;
            }
        } else
        if (adjf(s))
        {
            if (bolehadj && gender != 'm')
            {
                gender = 'f';
            } else
            {
                printf("NO\n");
                return 0;
            }
        } else
        if (nounm(s))
        {
            if (bolehnoun && gender != 'f')
            {
                gender = 'm';
                bolehadj = 0;
                bolehnoun = 0;
                bolehverb = 1;
            } else
            {
                printf("NO\n");
                return 0;
            }
        } else
        if (nounf(s))
        {
            if (bolehnoun && gender != 'm')
            {
                gender = 'f';
                bolehadj = 0;
                bolehnoun = 0;
                bolehverb = 1;
            } else
            {
                printf("NO\n");
                return 0;
            }
        } else
        if (verbm(s))
        {
            if (bolehverb && gender != 'f')
            {
                gender = 'm';
            } else
            {
                printf("NO\n");
                return 0;
            }
        } else
        if (verbf(s))
        {
            if (bolehverb && gender != 'm')
            {
                gender = 'f';
            } else
            {
                printf("NO\n");
                return 0;
            }
        } else
        {
            printf("NO\n");
            return 0;
        }
    }
    if (kata == 1)
    {
        printf("YES\n");
        return 0;
    }
    if (bolehnoun) printf("NO\n"); else printf("YES\n");
	return 0;
}