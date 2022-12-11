#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

char s[N];
int n, pre[N], suf[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + (s[i] >= 'a' && s[i] <= 'z');
	}
	for(int i = n; i >= 1; i --) {
		suf[i] = suf[i + 1] + (s[i] >= 'A' && s[i] <= 'Z');
	}
	int ans = n;
	for(int i = 0; i <= n; i ++) {
		ans = min(ans, pre[i] + suf[i + 1]);
	}
	printf("%d\n", ans);
	return 0;
}