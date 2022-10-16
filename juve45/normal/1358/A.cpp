#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define str string
#define fi first
#define se second
#define pb push_back
#define SET(a, b) memset(a, b, sizeof(a))
#define eps 1e-6
#define pi atan(1) * 4
#define mod 1000000007
#define inf 1000000000
#define llinf 1000000000000000000
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FORl(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORDl(i, a, b) for (ll i = (a); i >= (b); i--)
using namespace std;
int main () {
	int t;
	scanf("%d", &t);
	FOR(i, 1, t) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", (n * m + 1) / 2);
	}
	return 0;
}