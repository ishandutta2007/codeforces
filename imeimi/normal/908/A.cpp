#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef long long llong;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int ch[300];
char str[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ch['a'] = 1;
	ch['e'] = 1;
	ch['i'] = 1;
	ch['o'] = 1;
	ch['u'] = 1;

	cin >> str;
	int ans = 0;
	for (char * c = str; *c; ++c) {
		if ('0' <= *c && *c <= '9') ans += (*c - '0') % 2;
		else ans += ch[*c];
	}
	printf("%d\n", ans);

	return 0;
}