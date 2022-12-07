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

const int N = 200005;
int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += i - 1;
	}
	sort(a + 1, a + 1 + n);
	int f = 1;
	for (int i = 1; i < n; i++)
		if (a[i] > a[i + 1] - 1) f = 0;
	if (!f) printf(":(");
	else {
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i] - i + 1);
		printf("\n");
	}
	return 0;
}