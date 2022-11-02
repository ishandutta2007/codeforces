#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 10;

const int MAXD = 31401;

int N;
int X1[MAXN];
int Y1[MAXN];
int X2[MAXN];
int Y2[MAXN];

vector<set<pair<int, int> > > cover;

int main() {
	scanf("%d", &N);
	int minx = 50000, miny = 50000, maxx = -1, maxy =1;
	REP(i,MAXD) {
		cover.push_back(set<pair<int, int> >());
	}
	REP(i,N) {
		scanf("%d%d%d%d", X1+i, Y1+i, X2+i, Y2+i);
		minx = min(minx, X1[i]);
		minx = min(minx, X2[i]);
		miny = min(miny, Y1[i]);
		miny = min(miny, Y2[i]);
		maxx = max(maxx, X1[i]);
		maxx = max(maxx, X2[i]);
		maxy = max(maxy, Y1[i]);
		maxy = max(maxy, Y2[i]);
		FOR(y,Y1[i],Y2[i]-1) {
			cover[y].insert(make_pair(X1[i], X2[i]));
		}
	}
	
	if (maxx - minx != maxy - miny) {
		printf("NO\n");
		return 0;
	}
	
	bool ok = true;
	FOR(y, miny, maxy-1) {
		//printf("%d:\n", y);
		set<pair<int, int> >::iterator it = cover[y].begin();
		int last = minx;
		while (it != cover[y].end()) {
			//printf("%d %d\n", it->first, it->second);
			if (it->first != last) {
				ok = false;
				break;
			}
			last = it->second;
			++it;
		}
		if (last != maxx) ok = false;
		if (!ok) break;
	}

	printf("%s\n", ok ? "YES" : "NO");
	
	return 0;
}