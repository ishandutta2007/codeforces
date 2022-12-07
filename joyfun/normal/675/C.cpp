#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
//lower_bound(a+1,a+1+len1,x) - a - 1;
typedef long long LL;

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100005;
int n, a[N * 2];
map<long long, int> s;
long long sum[N * 2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	s[0]++;
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + a[i];
		s[sum[i]]++;		
	}
	int ans = n - 1;
	for (int i = n; i < 2 * n; i++) {
		long long tmp = sum[i - n];
		ans = min(ans, n - s[tmp]);
		sum[i] = sum[i - 1] + a[i];
		s[sum[i]]++;
		s[sum[i - n]]--;
	}
	printf("%d\n", ans);
	return 0;
}