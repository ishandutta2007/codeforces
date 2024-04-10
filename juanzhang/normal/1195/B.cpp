#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;

int main() {
	scanf("%I64d %I64d", &n, &k);
	k += n, k <<= 1;
	ll t = sqrt(k);
	for (; t >= 0; --t) {
		if (t * (t + 3) == k) {
			break;
		}
	}
	printf("%I64d", n - t);
  return 0;
}