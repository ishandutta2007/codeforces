#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define SZ(x) ((int)(x).size())
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = (int)1e9 + 7;

const int N = (int)1e6 + 7;
int a[ N ];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + n + 1);
		int sum = 0;
		for (int i = 1; i < n; i++) sum += a[i];
		if (a[n] > sum) puts("T");
		else if ( (a[n] + sum) % 2 ) puts("T");
		else puts("HL");
	}
	return 0;
}