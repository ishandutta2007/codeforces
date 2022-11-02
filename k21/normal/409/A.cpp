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

char line1[100], line2[100];

int main() {
	gets(line1);
	gets(line2);

	int sc = 0;
	for (int i = 0; i < strlen(line1); i+=2) {
		if (line1[i] == line2[i]) continue;

		if (line1[i] == '8' && line2[i] == '[') ++sc;
		if (line1[i] == '[' && line2[i] == '(') ++sc;
		if (line1[i] == '(' && line2[i] == '8') ++sc;

		if (line1[i] == '8' && line2[i] == '(') --sc;
		if (line1[i] == '[' && line2[i] == '8') --sc;
		if (line1[i] == '(' && line2[i] == '[') --sc;
	}

	if (sc > 0) {
		printf("TEAM 1 WINS\n");
	}
	if (sc < 0) {
		printf("TEAM 2 WINS\n");
	}
	if (sc == 0) {
		printf("TIE\n");
	}
	return 0;
}