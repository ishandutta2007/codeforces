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

string handles[100100][2];

int main() {
	scanf("%d ", &N);
	REP(i, N) {
		char buf[100];
		scanf("%s ", buf);
		handles[i][0] = buf;
		scanf("%s ", buf);
		handles[i][1] = buf;
	}
	
	string last = "";
	
	REP(ii,N) {
		int i;
		scanf("%d", &i);
		--i;
		bool ok0 = handles[i][0] > last;
		bool ok1 = handles[i][1] > last;
		if (ok0 && ok1) {
			last = min(handles[i][0], handles[i][1]);
		} else if (ok0) {
			last = handles[i][0];
		} else if (ok1) {
			last = handles[i][1];
		} else {
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	
	return 0;
}