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

const int N = 100005;

struct P {
	int x, y;
	P() {}
	P(double x, double y) : x(x), y(y) {}
	void read() {
		scanf("%d%d", &x, &y);
	}
	P operator - (const P& c) const {
		return P(x - c.x, y - c.y);
	}
	ll operator * (const P& c) const {
		return 1ll * x * c.y - 1ll * y * c.x;
	}
} a[N], b;
int n, m;

ll cal(P a, P b, P c) {
	return abs((b - a) * (c - b));
}

bool ins(P o, P a, P b, P c) {
	if (cal(o, a, b) + cal(o, b, c) + cal(o, a, c) == cal(a, b, c)) return true;
	return false;
}

bool ons(P x, P a, P b) {
	return (a - x) * (b - x) == 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) a[i].read();
	int f = 1;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		b.read();
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r)>>1;
			if ((a[mid] - a[0]) * (b - a[0]) <= 0) l = mid + 1;
			else r = mid;
		}
	//	printf("%d %lld\n", l - 1, (a[l - 1] - a[0]) * (b - a[0]));
		if (l == 1 || l == n || !ins(b, a[0], a[l - 1], a[l])) f = 0;
		if (l - 1 == 1 && ons(b, a[0], a[l - 1])) f = 0;
		if (l == n - 1 && ons(b, a[0], a[l])) f = 0;
		if (ons(b, a[l - 1], a[l])) f = 0;
	}
	printf("%s\n", f ? "YES" : "NO");
	return 0;
}