#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

const int N = 310;

int n, l[N], c[N];
map<int, int> dp;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", l + i);
	for(int i = 1; i <= n; i ++) scanf("%d", c + i);
	dp[0] = 0;
	for(int i = 1; i <= n; i ++) {
		for(map<int, int> :: iterator j = dp.begin(); j != dp.end(); j ++) {
			int x = __gcd(j -> first, l[i]);
			if(!dp[x] || dp[x] > j -> second + c[i]) {
				dp[x] = j -> second + c[i];
			}
		}
	}
	printf("%d\n", dp[1] ? dp[1] : -1);
	return 0;
}