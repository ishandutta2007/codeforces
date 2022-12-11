#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;

ll n, m, k, a[100010];

int main() {
//	ios :: sync_with_stdio(0);
	scanf("%I64d%I64d%I64d", &n, &m, &k); 
	for(int i = 1; i <= m; i ++) {
		scanf("%I64d", a + i);
	}
	int ans = 0;
	for(int i = 1; i <= m;) {
		int j;
		for(j = i; j <= m + 1; j ++) {
			if(j == m + 1 || ( (a[j] - i) / k != (a[i] - i) / k) ) {
				break ;
			}
		}
		ans ++;
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}