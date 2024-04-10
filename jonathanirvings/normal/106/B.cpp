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

int n,a[105],b[105],c[105],d[105];
bool boleh[105];
int minx,miny;

int main()
{
    scanf("%d",&n);
    FORN(i,1,n) scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    FORN(i,1,n) boleh[i] = 1;
    FORN(i,1,n)
    {
        FORN(j,1,n)
        {
            if (a[j] > a[i] && b[j] > b[i] && c[j] > c[i])
            {
                boleh[i] = 0;
                break;
            }
        }
    }
    minx = INF;
    FORN(i,1,n) if(boleh[i] && d[i] < minx)
    {
        minx = d[i];
        miny = i;
    }
    printf("%d\n",miny);
    return 0;
}