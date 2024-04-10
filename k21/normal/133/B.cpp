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
	int total = 0;
	REP(i,len) {
		total *= 16;
		switch(in[i]) {
			case '>': total += 8; break;
			case '<': total += 9; break;
			case '+': total += 10; break;
			case '-': total += 11; break;
			case '.': total += 12; break;
			case ',': total += 13; break;
			case '[': total += 14; break;
			case ']': total += 15; break;
		}
		total %= 1000003;
	}
	printf("%d\n", total);
	return 0;
}