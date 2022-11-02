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
typedef unsigned int uint;

char in[120];

uint reverse(uint x) {
	uint mask = 1<<7, mask2 = 1, res = 0;
	while (mask) {
		if (x & mask) res |= mask2;
		mask >>= 1; mask2 <<= 1;
	}
	return res;
}

int main() {
	gets(in);
	uint prev = 0;
	int len = strlen(in);
	REP(i,len) {
		prev = reverse(prev);
		int delta = prev-reverse(in[i]);
		if (delta < 0) delta += 256;
		printf("%d\n", delta);
		prev = in[i];
	}
	return 0;
}