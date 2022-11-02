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
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

using namespace std;

int a, c;

int main() {
	scanf("%d%d", &a, &c);
	int b = 0, add = 1;
	while (a || c) {
		int ba = a%3, bc = c%3;
		int bb = bc-ba;
		if (bb < 0) bb += 3;
		b += bb*add;
		add *= 3;
		a/=3; c/=3;
	}
	printf("%d\n", b);
	return 0;
}