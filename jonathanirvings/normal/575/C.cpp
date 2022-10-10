#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;
typedef vector<int> vi;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

#define FORN(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)

int cost[25][25]; int lvisit[25];
int rvisit[25]; int lvalue[25]; int rvalue[25]; int rmatch[25]; 
int m, n;

inline bool findmatch(int s) 
{ 
	lvisit[s] = true;
	REP(i,n) 
	{
		if(rvisit[i]||lvalue[s]+rvalue[i]!=cost[s][i]) continue; 
		rvisit[i] = true;
		if(rmatch[i]==-1 || findmatch(rmatch[i])) 
		{
			rmatch[i] = s;
			return true; 
		}
	}
	return false; 
}

inline void normalize() 
{
	int down = INF;
	vi lv;
	REP(i,m) if (lvisit[i]) lv.pb(i);
	/*REP(i,m) REP(j,n) if(!rvisit[j]) if(lvisit[i]) 
		down = min(down,lvalue[i]+rvalue[j]-cost[i][j]); */
	REP(j,n) if(!rvisit[j]) 
	{
		REP(k,SIZE(lv)) 
		{
			int i = lv[k];
			down = min(down,lvalue[i]+rvalue[j]-cost[i][j]); 
		}
	}
	REP(i,m) if(lvisit[i]) lvalue[i] -= down;
	REP(i,n) if(rvisit[i]) rvalue[i] += down; 
}

inline int calc() 
{ 
	RESET(rvalue,0);
	RESET(rmatch,-1);
	RESET(lvalue,0);
	RESET(lvisit,0);
	RESET(rvisit,0);
	REP(i,m) lvalue[i] = *max_element(cost[i],cost[i]+n);
	//REP(i,n) rvalue[i] = 0;
	//REP(i,n) rmatch[i] = -1; 
	REP(i,m) 
	{
		//CLEAR(lvisit); 
		RESET(lvisit,0);
		RESET(rvisit,0);
		//CLEAR(rvisit); 
		if(findmatch(i)) continue; 
		i--;
		normalize(); 
	}
	int ret = 0;
	REP(i,n) if (rmatch[i] != -1)
		ret += cost[rmatch[i]][i]; 
	return ret;
}

int N,x,risan = -INF;
int satu[105][105],dua[105][105];

void dfs(int now,int nowa,int nowb)
{
	//printf("1 == %d %d %d\n",now,nowa,nowb);
	if (now == N) return;
	if (nowa < N / 2)
	{
		++m;
		REP(i,n) cost[now][i] = satu[now][i];
		lvalue[now] = *max_element(cost[now],cost[now]+n);
		//RESET(lvisit,0);
		//RESET(rvisit,0);
		while (1)
		{
			RESET(lvisit,0);
			RESET(rvisit,0);
			if (findmatch(now)) break;
			normalize();
		}
		int ret = 0;
		REP(i,n) if (rmatch[i] != -1)
			ret += cost[rmatch[i]][i];
		MAX(risan,ret);
		dfs(now+1,nowa+1,nowb);
		REP(i,n) if(rmatch[i] == now)
			rmatch[i] = -1;
		--m;
	}
	//printf("2 == %d %d %d\n",now,nowa,nowb);
	if (nowb < N / 2)
	{
		++m;
		REP(i,n) cost[now][i] = dua[now][i];
		lvalue[now] = *max_element(cost[now],cost[now]+n);
		/*REP(i,m) 
		{
			REP(j,n) printf("%d ",cost[i][j]);
			puts("");
		}
		REP(i,n) printf("%d ",rmatch[i]);
		puts("");*/
		while (1)
		{
			RESET(lvisit,0);
			RESET(rvisit,0);
			if (findmatch(now)) break;
			normalize();
		}
		int ret = 0;
		REP(i,n) if (rmatch[i] != -1)
			ret += cost[rmatch[i]][i];
		MAX(risan,ret);
		dfs(now+1,nowa,nowb+1);
		REP(i,n) if(rmatch[i] == now)
			rmatch[i] = -1;
		--m;
	}
}

int main() {
	scanf("%d",&N);
	n = N;
	m = 0;
	RESET(rvalue,0);
	RESET(rmatch,-1);
	RESET(lvalue,0);
	RESET(lvisit,0);
	RESET(rvisit,0);
	REP(i,N) REP(j,N)
	{
		scanf("%d",&satu[i][j]);
	}
	REP(i,N) REP(j,N)
	{
		scanf("%d",&dua[i][j]);
	}
	dfs(0,0,0);
	/*REP(bit,1<<N) if(__builtin_popcount(bit) == N / 2)
	{
		REP(i,n) if(bit & (1 << i))
		{
			REP(j,n) 
			{
				cost[i][j] = satu[i][j];
			}
		} else 
		{
			REP(j,n) 
			{
				cost[i][j] = dua[i][j];
			}
		}
		m = n = N;
		int ashar = calc();
		MAX(risan,ashar);
	}*/
	printf("%d\n",risan);
}