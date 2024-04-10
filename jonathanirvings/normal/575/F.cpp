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

int n,x;
pii data[5005];
pii now;
LL risan = 0;

int main() {
	scanf("%d %d",&n,&x);
	now = mp(x,x);
	REP(i,n)
	{
		scanf("%d %d",&data[i].fi,&data[i].se);
		if (now.se < data[i].fi)
		{
			risan += data[i].fi - now.se;
			now = mp(now.se,data[i].fi);
		} else if (data[i].se < now.fi)
		{
			risan += now.fi - data[i].se;
			now = mp(data[i].se,now.fi);
		} else
		{
			MAX(now.fi,data[i].fi);
			MIN(now.se,data[i].se);
		}
	}
	cout << risan << endl;
}