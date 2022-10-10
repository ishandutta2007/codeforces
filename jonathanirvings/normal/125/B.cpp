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

int StringToInt(string a)
{
    char x[100];
    strcpy(x,a.c_str());
    int res;
    sscanf(x,"%d",&res);
    return res;
}

//end of jonathanirvings' template v1.0.0

int spaces = 0;
char c[5];

int main()
{
	while (scanf("%c",&c[0])!=EOF && c[0] != '\n')
	{
		scanf("%c%c",&c[1],&c[2]);
		if (c[2] == '>')
		{
			spaces += 2;
			FORN(i,1,spaces - 2) printf(" ");
			FORN(i,0,2) printf("%c",c[i]);
			puts("");
		} else	
		{
			scanf("%c",&c[3]);
			spaces -= 2;
			FORN(i,1,spaces) printf(" ");
			FORN(i,0,3) printf("%c",c[i]);
			puts("");
		}
	}
	return 0;
}