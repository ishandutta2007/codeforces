#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int pre = m + 1, cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (x == pre) {
			ans = max(ans, cnt);
			cnt = 1;
			pre = x;
		}
		else {
			cnt++;
			pre = x;
		}
	}
	ans = max(ans, cnt);
	printf("%d\n", ans);
	return 0;
}