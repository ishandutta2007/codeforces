#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e6 + 10;

int main() {
	char s[N], t[N];
	scanf("%s", t);
	int i = 0, j = 0;
	bool zeros = true, afterDot = false;
	int after = 0;
	while (t[j] != '\0') {
		if (afterDot) ++after;
		if (zeros && (t[j] == '0')) {
			++j;
			continue;
		}
		if (zeros && t[j] == '.') {
			++j;
			afterDot = true;
			continue;
		}
		if (zeros) {
			zeros = false;
			s[i] = t[j];
			++i;
			++j;
			continue;
		}
		if (t[j] == '.') {
			afterDot = true;
			++j;
			continue;
		}
		s[i] = t[j];
		++i;
		++j;
	}
	while (i > 0 && s[i - 1] == '0') {
		--i;
		--after;
	}
	s[i] = '\0';
	printf("%c", s[0]);
	if (i != 1) printf(".%s", s + 1);
	if (i - after - 1 != 0) printf("E%d", i - after - 1);
	return 0;
}