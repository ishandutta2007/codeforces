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

int N, K;

int main() {
	scanf("%d%d", &N, &K);
	
	vector<int> res;
	
	int min = 2, max = N;
	res.push_back(1);
	bool small = false;
	while (K > 1) {
		if (small) {
			res.push_back(min++);
		} else {
			res.push_back(max--);
		}
		small = !small;
		--K;
	}
	
	if (small) {
		FORD(i,max,min) {
			res.push_back(i);
		}
	} else {
		FOR(i,min,max) {
			res.push_back(i);
		}
	}
	
	REP(i,N) printf("%d%c", res[i], i == N-1 ? '\n' : ' ');
	
	return 0;
}