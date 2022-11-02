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

#define DEBUG(x) cout << '>' << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR2(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

char in[120];

int main() {
	gets(in);
	int len = strlen(in);
	bool res = false;
	REP(i,len) {
		if (in[i] == 'H' || in[i] == 'Q' || in[i] == '9') {
			res = true; break;
		}
	}
	printf(res ? "YES\n" : "NO\n");
	return 0;
}