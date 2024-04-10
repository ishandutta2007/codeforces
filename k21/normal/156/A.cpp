#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
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

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

char s1[2100], s2[2100];

int main() {
	scanf("%s", s1);
	scanf("%s", s2);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int best = 2100;
	FOR(off,-l2, l1) {
		int ch = 0;
		REP(i2,l2) {
			int i1 = i2+off;
			if (i1 < 0 || i1 >= l1) {++ch; continue;}
			if (s2[i2] != s1[i1]) {++ch; continue;}
		}
		if (ch < best) best = ch;
	}
	printf("%d\n", best);
	return 0;
}