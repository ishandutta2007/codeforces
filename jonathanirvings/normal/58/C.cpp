//Codeforces Beta Round 84
//29 Aug 2011

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
typedef pair<int,int> pii;

double EPS = 1e-6;
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
#define SORT(v) sort(v.begin(),v.end())
#define SORTA(arr,sz) sort(arr+1,arr+1+sz)

//end of jonathanirvings' template

int n;
int data1[100005],data2[100005];
int value[100005];

int main()
{
    int tot = -INF;
    scanf("%d",&n);
    FORN(i,1,n) scanf("%d",&data1[i]);
    FORN(i,1,n) data2[i] = i;
    FORD(i,n,1) data2[i] = min(data2[i],n - i + 1);
    FORN(i,1,n) 
    {
        int dif = data1[i] - data2[i];
        if (dif >= 0) value[dif]++;
    }
    FORN(i,0,100000) tot = max(tot,value[i]);
    printf("%d\n",n - tot);
	return 0;
}