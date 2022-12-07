#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 2005;
int a[N];

int main() {
	int n, t;
	scanf("%d", &n); while (n--) {
		scanf("%d", &t);
		a[t]++;
	}
	for (int i = 1; i < N; i++) a[i] += a[i - 1];
	int ans = 0;
	scanf("%d", &t);
	for (int i = t + 1; i <= 2000; i++) ans = max(ans, a[i] - a[i - t - 1]);
	printf("%d\n", ans);
	return 0;
}