#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<long long,int> pii;
typedef vector<long long> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(long long i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (long long)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 1000005;
int n;
char str[N];

int main() {
	scanf("%d", &n); scanf("%s", str + 1);
	ll x = 0, y = 0, d = 0, u = 0, l = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		x += 2 * u; y -= 2 * d;
		if (str[i - 1] == 'U') u++, x++;
		if (str[i - 1] == 'D') d--, y++;
		while (d - 1 < u && r < n) if (str[++r] == 'D') d++, y += 2 * (r - i + 1) - 1;
		while (d < u && r == n) if (str[++l] == 'U') u--, x -= 2 * (i - l) - 1;
		if (d - 1 == u) printf("%lld ",  x + y + i - 1);
		else printf("%lld ", x + y + n - i + 1);
	}
	return 0;
}