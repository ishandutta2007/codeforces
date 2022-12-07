#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int k[4];

int main() {
	for (int i = 0; i < 4; i++) scanf("%d", &k[i]);
	int cnt = min(k[0], min(k[2], k[3]));
	int ans = cnt * 256;
	k[0] -= cnt; k[2] -= cnt; k[3] -= cnt;
	cnt = min(k[0], k[1]);
	ans += cnt * 32;
	printf("%d\n", ans);
	return 0;
}