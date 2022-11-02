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
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int N;
int D[2100][2100];
vector<pair<int, int>> edges[2100];

bool checkDist(int start, int from, int at, int dist) {
	/*
	DEBUG(start);
	DEBUG(from);
	DEBUG(at);
	DEBUG(dist);
	*/
	if (D[start][at] != dist) {
		return false;
	}
	
	for (auto& next : edges[at]) if (next.second != from) {
		if (!checkDist(start, at, next.second, dist + next.first)) {
			return false;
		}
	}
	
	return true;
}

int main() {
	scanf("%d", &N);
	
	REP(i,N) REP(j,N) {
		scanf("%d", &D[i][j]);
	}
	
	REP(i,N) REP(j,N) if (D[i][j] != D[j][i] || (D[i][j] == 0) != (i == j)) {
		printf("NO\n");
		return 0;
	}
	
	vector<pair<int, int>> ord;
	vector<pair<int, int>> closest;
	REP(i,N) {
		ord.push_back({D[0][i], i});
		closest.push_back({D[0][i], 0});
	}
	sort(ord.begin(), ord.end());
	
	FOR(ii,1,N-1) {
		int i = ord[ii].second;
		int j = closest[i].second;
		
		edges[j].push_back({D[i][j], i});
		edges[i].push_back({D[i][j], j});
		
		REP(k,N) {
			closest[k] = min(closest[k], {D[i][k], i});
		}
	}
	
	REP(i,N) {
		//DEBUG(i);
		if (!checkDist(i, -1, i, 0)) {
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	
	return 0;
}