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
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SORT(v) sort(v.begin(),v.end())
#define SORTA(arr,sz) sort(arr+1,arr+1+sz)

//end of jonathanirvings' template

int main()
{
    int n;
    scanf("%d",&n);
    if (n <= 10 || n >= 22) printf("0\n"); else
    {
          if (n != 20) printf("4\n"); else printf("15\n");
    }
    return 0;
}