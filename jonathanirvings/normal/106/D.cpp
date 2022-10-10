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

int r,c,k;
char peta[1005][1005];
int maxup[1005][1005],maxleft[1005][1005],maxdown[1005][1005],maxright[1005][1005];
vector <char> ans;
char dir[100005];
int steps[100005];

int main()
{
    scanf("%d %d",&r,&c);
    FORN(i,1,r)
    {
        scanf("\n");
        FORN(j,1,c) scanf("%c",&peta[i][j]);
    }
    FORN(i,1,r)
    {
        FORN(j,1,c) if(peta[i][j] != '#')
        {
            if (peta[i][j-1] == '#') maxleft[i][j] = 1;
            else maxleft[i][j] = maxleft[i][j-1] + 1;
        }
    }
    FORN(i,1,r)
    {
        FORD(j,c,1) if(peta[i][j] != '#')
        {
            if (peta[i][j+1] == '#') maxright[i][j] = 1;
            else maxright[i][j] = maxright[i][j+1] + 1;
        }
    }
    FORN(j,1,c)
    {
        FORN(i,1,r) if(peta[i][j] != '#')
        {
            if (peta[i-1][j] == '#') maxup[i][j] = 1;
            else maxup[i][j] = maxup[i-1][j] + 1;
        }
    }
    FORN(j,1,c)
    {
        FORD(i,r,1) if(peta[i][j] != '#')
        {
            if (peta[i+1][j] == '#') maxdown[i][j] = 1;
            else maxdown[i][j] = maxdown[i+1][j] + 1;
        }
    }
    /*FORN(i,1,r)
    {
        FORN(j,1,c) printf("%d",maxleft[i][j]);
        printf("\n");
    }*/
    scanf("\n%d",&k);
    FORN(i,1,k) scanf("\n%c %d",&dir[i],&steps[i]);
    FORN(i,1,r) FORN(j,1,c)
    {
        if (peta[i][j] >= 'A' && peta[i][j] <= 'Z')
        {
            bool bisa = 1;
            int posx = i;
            int posy = j;
            FORN(x,1,k)
            {
                if (dir[x] == 'N')
                {
                    if (steps[x] >= maxup[posx][posy])
                    {
                        bisa = 0;
                        break;
                    }
                    posx = posx - steps[x];
                }
                if (dir[x] == 'S')
                {
                    if (steps[x] >= maxdown[posx][posy])
                    {
                        bisa = 0;
                        break;
                    }
                    posx = posx + steps[x];
                }
                if (dir[x] == 'E')
                {
                    if (steps[x] >= maxright[posx][posy])
                    {
                        bisa = 0;
                        break;
                    }
                    posy = posy + steps[x];
                }
                if (dir[x] == 'W')
                {
                    if (steps[x] >= maxleft[posx][posy])
                    {
                        bisa = 0;
                        break;
                    }
                    posy = posy - steps[x];
                }
            }
            if (bisa) ans.pb(peta[i][j]);
        }
    }
    if (ans.empty()) printf("no solution\n"); else
    {
        SORT(ans);
        int anssz = ans.size();
        FOR(i,0,anssz) printf("%c",ans[i]);
        printf("\n");
    }
	return 0;
}