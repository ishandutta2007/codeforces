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

//end of jonathanirvings' template

//Codeforces Beta Round #88 - 23 Sep 2011

LL a,b;
LL MOD;

int main()
{
    scanf("%lld %lld %lld",&a,&b,&MOD);
    if (MOD - 1 <= b)
    {
        printf("2\n");
        return 0;
    }
    bool bisa = 0;
    FORL(i,0,min(a,MOD))
    {
        LL angka = (LL)i * (LL)1e9;
        LL beda = angka % MOD;
        if (beda >= 1 && beda <= MOD - b - 1)
        {
            bisa = 1;
            printf("1 %09lld\n",i);
            break;
        }
    }
    if (!bisa) printf("2\n");
	return 0;
}