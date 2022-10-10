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

int n,k;
char data[100005];

void OUT(void)
{
    FORN(i,1,n) printf("%c",data[i]);
    puts("");
}

int main()
{
    scanf("%d %d\n",&n,&k);
    FORN(i,1,n) scanf("%c",&data[i]);
    FOR(i,1,n) 
    {
        if (k == 0) break;
        if (data[i] == '4' && data[i+1] == '7')
        {
            if (i % 2 && i <= n - 2 && data[i+2] == '7')
            {
                if (k % 2)
                {
                    data[i+1] = '4';
                }
                OUT();
                return 0;
            } else
            {
                k--;
                if (i % 2)
                {
                    data[i] = '4';
                    data[i+1] = '4';
                } else
                {
                    data[i] = '7';
                    data[i+1] = '7';
                }
            }
        }
        if (data[i] == '4' && data[i+1] == '4')
        {
            if (i % 2 && i <= n - 2 && data[i+2] == '7')
            {
                if (k % 2)
                {
                    data[i+1] = '7';
                }
                OUT();
                return 0;
            }
        }
    }
    OUT();
	return 0;
}