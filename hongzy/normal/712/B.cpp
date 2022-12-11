#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 4e5 + 10;

char s[N];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if(n & 1) {
		puts("-1");
		return 0;
	}
	int a = 0, b = 0, c = 0, d = 0, ans = 1e9;
	for(int i = 1; i <= n; i ++) {
		if(s[i] == 'R') a ++;
		if(s[i] == 'L') b ++;
		if(s[i] == 'U') c ++;
		if(s[i] == 'D') d ++;
	}
	for(int i = 0; 2 * i <= n; i ++) { //a = b = i
		int j = (n - 2 * i) >> 1;
		int cost1 = 0, cost2 = 0;
		if(a > i) cost1 += a - i;
		else cost2 += i - a;
		if(b > i) cost1 += b - i;
		else cost2 += i - b;
		if(c > j) cost1 += c - j;
		else cost2 += j - c;
		if(d > j) cost1 += d - j;
		else cost2 += j - d;
		if(cost1 == cost2) {
			ans = min(ans, cost1);
		}
	}
	printf("%d\n", ans);
	return 0;
}