#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
const ll N = 1000005;
int n, vis[N];

void get() {
	for (ll i = 2; i < N; i++) {
		if (vis[i]) continue;
		for (ll j = i * i; j < N; j += i)
			vis[j] = 1;
	}
}

int main() {
	get();
	scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		if (vis[i] && vis[n - i]) {
			printf("%d %d\n", i, n - i);
			break;
		}
	}
	return 0;
}