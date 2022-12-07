#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long ll;

int n;
ll a, b;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%llu%llu", &a, &b);
		ll x = (1ULL<<63) - 1;
		for (int i = 62; i >= 0; i--) {
			if (x >= a && x <= b) {
				break;
			}
			if ((x^(1ULL<<i)) < a) continue;
			x ^= (1ULL<<i);
		}
		printf("%llu\n", x);
	}
	return 0;
}