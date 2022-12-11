#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 1010;

int n, k, a[N], cnt[N];

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i), cnt[a[i]] ++;
	int ans = 0, cur = 0;
	for(int i = 1; i <= k; i ++) {
		if(cnt[i] >= 2) {
			while(cnt[i] >= 2)
				ans += 2, cnt[i] -= 2;
		}
		if(cnt[i] >= 1) {
			if(!cur) ans ++;
			cur ^= 1;
			cnt[i] --;
		}
	}
	printf("%d\n", ans);
	return 0;
}