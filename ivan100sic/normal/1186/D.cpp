#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, a[100005], b[100005];
char s[16];

int main() {
	scanf("%lld", &n);
	for (int i=0; i<n; i++) {
		scanf("%s", s);
		int x = 0;
		while (s[x] != '.')
			x++;
		a[i] = stoi(string(s, s+x));
		b[i] = stoi(string(s+x+1));
		if (s[0] == '-' && b[i] != 0) {
			b[i] = 100000 - b[i];
			a[i]--;
		}
	}
	ll sum = accumulate(b, b+n, 0ll);
	ll k = sum / 100000;
	for (ll i=0; i<n; i++) {
		if (k > 0 && b[i] > 0) {
			a[i]++;
			k--;
		}
		printf("%lld\n", a[i]);
	}
}