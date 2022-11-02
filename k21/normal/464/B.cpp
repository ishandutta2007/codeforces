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

vector<int> D[10];

ll dist(const vector<int>& v1, const vector<int>& v2) {
	ll r = 0;
	REP(i,3) {
		ll d = v1[i] - v2[i];
		r += d*d;
	}
	return r;
}

bool right(const vector<int>& v1, const vector<int>& v2, const vector<int>& v3) {
	vector<ll> d1, d2;
	REP(i,3) d1.push_back(v1[i] - v2[i]);
	REP(i,3) d2.push_back(v3[i] - v2[i]);

	ll x = d1[0]*d2[0] + d1[1]*d2[1] + d1[2]*d2[2];
	return x == 0;
}

bool isCube() {
	vector<int>* c1, * c2;
	c1 = &D[0], c2 = &D[1];
	if (*c1 > *c2) swap(c1, c2);

	FOR(i,2,7) {
		if (D[i] < *c1) {
			c2 = c1;
			c1 = &D[i];
		} else if (D[i] < *c2) {
			c2 = &D[i];
		}
	}

	ll d = dist(*c1, *c2);

	REP(i,8) {
		vector<int> ngh;
		REP(j,8) {
			if (dist(D[i], D[j]) == d) ngh.push_back(j);
		}
		if (ngh.size() != 3) return false;
		if (!right(D[ngh[0]], D[i], D[ngh[1]])) return false;
		if (!right(D[ngh[0]], D[i], D[ngh[2]])) return false;
		if (!right(D[ngh[1]], D[i], D[ngh[2]])) return false;
	}

	return true;
}

int main() {
	REP(i,8) REP(j,3) {
		int d;
		scanf("%d", &d);
		D[i].push_back(d);
	}
	REP(i,8) REP(j,3) D[i][j] *= 2;
	
	REP(i,8) {
		sort(D[i].begin(), D[i].end());
	}
	
	bool n = true;
	while (n) {
		if (isCube()) {
			printf("YES\n");
			REP(i,8) {
				printf("%d %d %d\n", D[i][0] / 2, D[i][1] / 2, D[i][2] / 2);
			}
			return 0;
		}
		n = false;
		REP(i,8) {
			if (next_permutation(D[i].begin(), D[i].end())) {
				n = true;
				break;
			}
		}
	}
	
	printf("NO\n");
	return 0;
}