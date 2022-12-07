#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
using namespace std;

const int MOD = 1000000007;
const int N = 505;
const int MAXN = 20005;
int n, a, cnt = 0, num[MAXN], c[20005][1005];
map<int ,int> v;

void getnum(int x) {
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			if (v.count(i)) {
				num[v[i]]++;
				x /= i;
			}
			else {
				v[i] = ++cnt;
				num[v[i]]++;
				x /= i;
			}
		}
	}	
	if (x == 1) return;
	if (v.count(x)) {
		num[v[x]]++;
	}
	else {
		v[x] = ++cnt;
		num[v[x]]++;
	}
}

void init() {
	c[0][0] = 1;
	for (int i = 1; i <= 17000; i++)
		for (int j = 0; j <= i && j <= 1000; j++)
			if (j == 0 || j == i) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
}

__int64 cal(int k) {
	return c[k + n - 1][n - 1];
}

__int64 solve() {
	__int64 ans = 1;
	for (int i = 1; i <= cnt; i++) 
		ans = ans * cal(num[i]) % MOD;
	return ans;
}

int main() {
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		getnum(a);
	}
	printf("%I64d\n", solve());
	return 0;
}